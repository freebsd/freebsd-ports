--- unix/plugins/SerialPlugin/sqUnixSerial.c.org	2012-09-24 15:29:28.000000000 +0900
+++ unix/plugins/SerialPlugin/sqUnixSerial.c	2012-09-24 15:29:38.000000000 +0900
@@ -21,7 +21,7 @@
 #define PORT_NAME_SIZE 64
 
 static const char serialPortBaseName[]		= "/dev/tty";
-static const char serialPortBaseNameDefault[]	= "/dev/ttyS0";
+static const char serialPortBaseNameDefault[]	= "/dev/ttyU0";
 
 /* stopBits	0=1.5, 1=1, 2=2 */
 /* I don't know how to get 1.5 stop bits. Oh well. So you get 2 instead */
