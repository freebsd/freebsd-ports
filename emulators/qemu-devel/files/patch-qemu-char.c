--- qemu-char.c.orig	2015-12-16 00:54:18 UTC
+++ qemu-char.c
@@ -1507,10 +1507,14 @@ static void tty_serial_init(int fd, int 
     cfsetospeed(&tty, spd);
 
     tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP
-                          |INLCR|IGNCR|ICRNL|IXON);
-    tty.c_oflag |= OPOST;
+                          |INLCR|IGNCR|ICRNL|IXON|IMAXBEL);
+    tty.c_oflag &= ~OPOST; /* Don't do any output processing! */
     tty.c_lflag &= ~(ECHO|ECHONL|ICANON|IEXTEN|ISIG);
     tty.c_cflag &= ~(CSIZE|PARENB|PARODD|CRTSCTS|CSTOPB);
+#ifdef __FreeBSD__
+    cfmakeraw(&tty);
+#endif
+	      
     switch(data_bits) {
     default:
     case 8:
