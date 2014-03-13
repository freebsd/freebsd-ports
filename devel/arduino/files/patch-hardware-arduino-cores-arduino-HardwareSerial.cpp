--- hardware/arduino/cores/arduino/HardwareSerial.cpp.orig	2013-05-17 12:48:38.000000000 -0700
+++ hardware/arduino/cores/arduino/HardwareSerial.cpp	2013-06-30 12:21:21.000000000 -0700
@@ -89,7 +89,7 @@
 
 inline void store_char(unsigned char c, ring_buffer *buffer)
 {
-  int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;
+  unsigned int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;
 
   // if we should be storing the received character into the location
   // just before the tail (meaning that the head would advance to the
@@ -124,14 +124,14 @@
       unsigned char c = UDR0;
       store_char(c, &rx_buffer);
     } else {
-      unsigned char c = UDR0;
+      unsigned char c __attribute__((unused)) = UDR0;
     };
   #elif defined(UDR)
     if (bit_is_clear(UCSRA, PE)) {
       unsigned char c = UDR;
       store_char(c, &rx_buffer);
     } else {
-      unsigned char c = UDR;
+      unsigned char c __attribute__((unused)) = UDR;
     };
   #else
     #error UDR not defined
@@ -150,7 +150,7 @@
       unsigned char c = UDR1;
       store_char(c, &rx_buffer1);
     } else {
-      unsigned char c = UDR1;
+      unsigned char c __attribute__((unused)) = UDR1;
     };
   }
 #endif
@@ -165,7 +165,7 @@
       unsigned char c = UDR2;
       store_char(c, &rx_buffer2);
     } else {
-      unsigned char c = UDR2;
+      unsigned char c __attribute__((unused)) = UDR2;
     };
   }
 #endif
@@ -180,7 +180,7 @@
       unsigned char c = UDR3;
       store_char(c, &rx_buffer3);
     } else {
-      unsigned char c = UDR3;
+      unsigned char c __attribute__((unused)) = UDR3;
     };
   }
 #endif
@@ -365,7 +365,6 @@
 void HardwareSerial::begin(unsigned long baud, byte config)
 {
   uint16_t baud_setting;
-  uint8_t current_config;
   bool use_u2x = true;
 
 #if F_CPU == 16000000UL
@@ -459,7 +458,7 @@
 
 size_t HardwareSerial::write(uint8_t c)
 {
-  int i = (_tx_buffer->head + 1) % SERIAL_BUFFER_SIZE;
+  unsigned int i = (_tx_buffer->head + 1) % SERIAL_BUFFER_SIZE;
 	
   // If the output buffer is full, there's nothing for it other than to 
   // wait for the interrupt handler to empty it a bit
