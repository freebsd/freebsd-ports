--- src/rbsb.c.orig	1998-12-29 16:16:25 UTC
+++ src/rbsb.c
@@ -296,7 +296,7 @@ io_mode(int fd, int n)
 			tty.c_iflag |= IXOFF;
 
 		 /* No echo, crlf mapping, INTR, QUIT, delays, no erase/kill */
-		tty.c_lflag &= ~(ECHO | ICANON | ISIG);
+		tty.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
 		tty.c_oflag = 0;	/* Transparent output */
 
 		tty.c_cflag &= ~(PARENB);	/* Same baud rate, disable parity */
