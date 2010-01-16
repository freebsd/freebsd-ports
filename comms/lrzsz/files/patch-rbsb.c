--- src/rbsb.c.org	2010-01-15 22:41:21.000000000 +0900
+++ src/rbsb.c	2010-01-15 22:41:34.000000000 +0900
@@ -296,7 +296,7 @@
 			tty.c_iflag |= IXOFF;
 
 		 /* No echo, crlf mapping, INTR, QUIT, delays, no erase/kill */
-		tty.c_lflag &= ~(ECHO | ICANON | ISIG);
+		tty.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
 		tty.c_oflag = 0;	/* Transparent output */
 
 		tty.c_cflag &= ~(PARENB);	/* Same baud rate, disable parity */
