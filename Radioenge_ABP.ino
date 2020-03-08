/* Exemplo de código ABP feito por Samuel Schwiderke em 07/03/2020
 *  As Key utilizadas foram escritas no mote através de comando AT utilizando o Route Serial disponivel em https://github.com/Radioenge/Arduino-Route-Serial
 *  Pode ser utilizado também o software Firmware e Software LoRaWAN v1r3s22 disponibilizado em: https://www.radioenge.com.br/solucoes/iot/17-modulo-lorawan.html
 *  Vou deixar em comentado junto também os espaços para colocar as KEY e o comando no void setup para quem não quiser utilizar os comandos AT, porém ocupam mais espaço
 *  e fica mais pesado o código.
 */


#include <LoRaWAN.h>

/* Includes ---------------------- */
#include <SoftwareSerial.h>
#include <stdint.h>

/* SoftwareSerial handles */
SoftwareSerial* hSerialCommands = NULL;

/*char APPSKEY[] = "50:d1:ad:39:e5:b3:a6:fc:ff:db:3e:a6:3e:e6:5a:AA";
char NWKSKEY[] = "50:d1:ad:39:e5:b3:a6:fc:ff:db:3e:a6:3e:e6:5a:00";
const char *devAddr = "26031600";
*/
char str_counter[32];
int counter = 0;

void setup() {
  Serial.begin(9600); /* Initialize monitor serial */
  Serial.println("Initializing...");
  delay(5000);

  /* Initialize SoftwareSerial */
  hSerialCommands = SerialCommandsInit(7, 6, 9600);
  
  SendAtCommand(AT_NJM, AtSet, "0");// comando para alterar a autenticação para ABP
  /*SendAtCommand(AT_APPSKEY, AtSet, APPSKEY); envia comando para registra appkey
  SendAtCommand(AT_NWKSKEY, AtSet, NWKSKEY);  envia comando para registra nwskey
  SendAtCommand(AT_DEVaDDR, AtSet, DADDR); */
  
  
}

void loop() {
  /* Sends a string containing a counter every 15s */
  sprintf(str_counter, "Counter: %d\r\n\0", counter++);
  Serial.println(str_counter);
  SendString(str_counter, 2);
  delay(15000);
  
}
