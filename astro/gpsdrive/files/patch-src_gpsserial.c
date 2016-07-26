--- src/gpsserial.c.orig	2004-02-12 17:42:53 UTC
+++ src/gpsserial.c
@@ -178,7 +178,9 @@ readinput_init (void)
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
