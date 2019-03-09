//Line Tracking IO define
#define LT_R digitalRead(10)
#define LT_M digitalRead(4)
#define LT_L digitalRead(2)

#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define ENA 6

#define carSpeed 200
#define fastCarSpeed 220

void forward(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go forward!");
}

void back(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("go back!");
}

void left(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go left!");
}

void fastLeft(){
  analogWrite(ENA, fastCarSpeed);
  analogWrite(ENB, fastCarSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go left!");
}

void right(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  Serial.println("go right!");
} 

void fastRight(){
  analogWrite(ENA, fastCarSpeed);
  analogWrite(ENB, fastCarSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  Serial.println("go right!");
}

void stop(){
   digitalWrite(ENA, LOW);
   digitalWrite(ENB, LOW);
   Serial.println("Stop!");
} 

void setup(){
  Serial.begin(9600);
}

void loop() {
  if(LT_R){
    forward();
    while(LT_R);
  }
  else if(LT_L) {
    left();
    while(!LT_R);
  }
  /*else if(LT_L) {
    left();
    while(LT_L);
  }
  else if(!LT_L && !LT_M && !LT_R) {
    fastLeft();
    while(!LT_L && !LT_M && !LT_R);
  }*/
}
