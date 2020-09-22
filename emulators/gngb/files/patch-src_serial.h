--- src/serial.h.orig	2003-05-16 16:35:58 UTC
+++ src/serial.h
@@ -21,7 +21,7 @@
 
 #include "global.h"
 
-struct {
+typedef struct {
   Sint16 cycle_todo;
   Uint16 p;
   Uint8 b;
@@ -29,10 +29,12 @@ struct {
   Uint8 check;
   Uint8 wait;
   Uint8 ready2read;
-}gbserial;
+} gbserial_t;
 
-Sint16 serial_cycle_todo;
-Sint8 gblisten;
+extern gbserial_t gbserial;
+
+extern Sint16 serial_cycle_todo;
+extern Sint8 gblisten;
 
 void gbserial_init(int server_side,char *servername);
 void gbserial_close(void);
