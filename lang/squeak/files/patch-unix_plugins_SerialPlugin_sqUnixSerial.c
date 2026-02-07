--- unix/plugins/SerialPlugin/sqUnixSerial.c.orig	2011-03-14 05:01:56 UTC
+++ unix/plugins/SerialPlugin/sqUnixSerial.c
@@ -21,7 +21,7 @@
 #define PORT_NAME_SIZE 64
 
 static const char serialPortBaseName[]		= "/dev/tty";
-static const char serialPortBaseNameDefault[]	= "/dev/ttyS0";
+static const char serialPortBaseNameDefault[]	= "/dev/ttyU0";
 
 /* stopBits	0=1.5, 1=1, 2=2 */
 /* I don't know how to get 1.5 stop bits. Oh well. So you get 2 instead */
@@ -94,10 +94,8 @@ static drDecode dataRateDecode[] = {
 #endif
 #if defined(B500000)		/* missing on GNU/Linux prior to 2.2 */
   { 500000, B500000 },
-  { 576000, B576000 },
   { 921600, B921600 },
   { 1000000, B1000000 },
-  { 1152000, B1152000 },
   { 1500000, B1500000 },
   { 2000000, B2000000 },
 #endif
