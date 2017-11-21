#include <Keypad.h>

bool digitandoSenha = false;
String senhaDigitada;
String senha = "4321";

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {5, 4, 3, A0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);

  pinMode(A0, INPUT);
}

void loop() {
  char key = keypad.getKey();

  if (key) {

    if (digitandoSenha && key != '#') {
      senhaDigitada += key;
      Serial.println(senhaDigitada);
    }


    if (key == '*') {
      digitandoSenha = true;
      Serial.println("Iniciando digitação da senha...");

    }
    if (key == '#') {
      digitandoSenha = false;
      Serial.println("Finaliza senha");

      if(senhaDigitada == senha){
          Serial.println("Alarme desativado");
        }
      else{
         Serial.println("Acesso negado");
      }


    }

    //    if(digitandoSenha){
    //      senhaDigitada +=key;
    //      Serial.println(senhaDigitada);
    //      }


    //Serial.println(key);
  }
}
