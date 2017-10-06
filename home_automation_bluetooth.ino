int pirPin=12;        //pin for PIR motion sensor
int buzzerPin=8;      //pin for Buzzer to make noise
int lightRelay=7;    //pin for relay connected to light 
int fanRelay=5;      //pin for relay connected to fan
String command;  //String command to control equipment

void setup() {
  pinMode(pirPin,INPUT);   //declaring pir motion sensor pin as input
  pinMode(lightRelay,OUTPUT);   //declaring relay pin of light as output
  pinMode(fanRelay,OUTPUT);    //declaring relay pin of fan as output
  Serial.begin(9600);        //turning on serial monitor at 9600 baud rate
}

void loop() {
  if (Serial.available()>0){   //checking any command is available in serial monitor or not
    command=Serial.readString();     // reading value from serial monitor
    Serial.println(command);   //printing value on serial monitor
    if(command=="lightOn"  ){            //checking the command equals to lightOn
      digitalWrite(lightRelay,HIGH);     //activating relay 
      delay(500);                        //delay of half second
      }
    else if (command=="lightOff"){       //checking the command equals to lightOff
      digitalWrite(lightRelay,LOW);      //activating relay 
      delay(500);                        //delay of half second
      }
    else if (command=="fanON"){          //checking the command equals to fanON
      digitalWrite(fanRelay,HIGH);       //activating relay 
      delay(500);                        //delay of half second
      }
    else if (command=="fanOff"){         //checking the command equals to fanOff
      digitalWrite(fanRelay,LOW);       //activating relay 
      delay(500);                       //delay of half second
      }

      
    }
  intruderDetection(); //function for detection of intruder using pirmotion sensor
  delay(500);          //delay in total loop
}

void intruderDetection(){
  int value=digitalRead(pirPin);   // reading value from pir pin
  if (value==HIGH){                //checking value is high or not
    tone(buzzerPin,2500,500);      //starting buzzer with 2500Hz frequency for 0.5s
    delay(1000);                   //delay of 1s in function
    }
  else {
    //doing nothing if value is low
    }
  }

