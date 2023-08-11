#include <AccelStepper.h>

#define rightSensorPin 3 
#define leftSensorPin 4  

// Stepper motor configuration
const int motorInterfaceType = 1;
AccelStepper stepper(motorInterfaceType, 5, 6);

void setup() {
 
  pinMode(rightSensorPin, INPUT_PULLUP);
  pinMode(leftSensorPin, INPUT_PULLUP);

  
 
  stepper.setMaxSpeed(2000); 
  stepper.setAcceleration(1000);
}

void loop() {
 
  if (digitalRead(rightSensorPin) == LOW) {
    rotateClockwise();
  }

  
  if (digitalRead(leftSensorPin) == LOW) {

    rotateCounterclockwise();
    
  }
}

void rotateClockwise() {
  stepper.moveTo(360); 
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
 
  stepper.stop();
  stepper.setCurrentPosition(0);
}

void rotateCounterclockwise() {
  stepper.moveTo(-360); 
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  // Stop the motor after rotating
  stepper.stop();
  stepper.setCurrentPosition(0);
}
