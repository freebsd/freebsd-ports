--- hardware/arduino/cores/arduino/HardwareSerial.cpp.orig	2012-07-28 21:20:49.000000000 -0700
+++ hardware/arduino/cores/arduino/HardwareSerial.cpp	2012-07-28 21:24:52.000000000 -0700
@@ -129,8 +129,6 @@
     unsigned char c = UDR1;
     store_char(c, &rx_buffer1);
   }
-#elif defined(SIG_USART1_RECV)
-  #error SIG_USART1_RECV
 #endif
 
 #if defined(USART2_RX_vect) && defined(UDR2)
@@ -142,8 +140,6 @@
     unsigned char c = UDR2;
     store_char(c, &rx_buffer2);
   }
-#elif defined(SIG_USART2_RECV)
-  #error SIG_USART2_RECV
 #endif
 
 #if defined(USART3_RX_vect) && defined(UDR3)
@@ -155,8 +151,6 @@
     unsigned char c = UDR3;
     store_char(c, &rx_buffer3);
   }
-#elif defined(SIG_USART3_RECV)
-  #error SIG_USART3_RECV
 #endif
 
 void serialEventRun(void)
