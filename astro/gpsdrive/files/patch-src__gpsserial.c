--- src/gpsserial.c.orig	Thu Feb 12 18:42:53 2004
+++ src/gpsserial.c	Mon Sep  6 00:44:34 2004
@@ -178,7 +178,9 @@
   CLOCAL  : local connection, no modem contol
   CREAD   : enable receiving characters
 */
-  newtio.c_cflag = (11 + serialspeed) | CS8 | CLOCAL | CREAD;
+  { int t[] = { 2400, 4800, 9600, 19200, 38400 };
+  newtio.c_ispeed = newtio.c_ospeed = t[serialspeed]; }
+  newtio.c_cflag = CS8 | CLOCAL | CREAD;
   newtio.c_cflag &= ~(PARENB | CRTSCTS);
 /*
   IGNPAR  : ignore bytes with parity errors
