#include "Wire.h"
#include "IO_Extender.h"
#include "NRF.h"


const bool DEBUG_PRINT = true;

enum RotaryEncoderState {
  Nothing,    //0
  Pressed,    //1 
  Released,   //2
  SpunRight,  //3
  SpunLeft    //4
};

enum IOLabels {
  A, //0
  B, //1
  C, //2
  D  //3
};

struct GyroAngleData {
    int X;
    int Y;
};

int prevPotA = 0;
int prevPotB = 0;


void setup() {
  Serial.begin(9600);
  Wire.begin();

  
  //setupRotaryEncoder();
  //setupGyro();
  //setupButtons();
  setupScreen();
  setupNRF();
  

  //setupIOExtender();
}

void loop() {
  /*
  readIOExtenderPinValues();
  RotaryEncoderState rotaryEncoderState = readRotaryEncoder();
    
  uint8_t buttonA = getButtonState(A);
  uint8_t buttonB = getButtonState(B);
  uint8_t buttonC = getButtonState(C);
  uint8_t buttonD = getButtonState(D);

  rc_data.joy1_Y = 127;
  if(getButtonState(A) == HIGH){
    rc_data.joy1_Y = 200;
    Serial.println("Button A Pressed");
  }

  if(getButtonState(B) == HIGH){
    Serial.println("Button B Pressed");
  }

  if(getButtonState(C) == HIGH){
    Serial.println("Button C Pressed");
  }

  if(getButtonState(D) == HIGH){
    Serial.println("Button D Pressed");
  }

  int potBValue = getPotValue(B);
  int potAValue = getPotValue(A);


  if(potAValue != prevPotA || potBValue != prevPotB){
    Serial.print("Pot A : ");
    Serial.print(potAValue);
    Serial.print("\tPot B : ");
    Serial.println(potBValue);
  }
  prevPotA = potAValue;
  prevPotB = potBValue; 
  */
  sendNRFData();
  //delay(500);
  updateScreen();
}
