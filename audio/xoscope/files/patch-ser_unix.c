--- ser_unix.c.orig	2008-12-17 12:46:15.000000000 -0500
+++ ser_unix.c	2013-11-05 18:03:15.000000000 -0500
@@ -14,7 +14,14 @@
 #include <errno.h>
 #include <unistd.h>
 #include <string.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+#ifdef BSD
+#include <termios.h>
+#else
 #include <termio.h>
+#endif
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
@@ -24,7 +31,11 @@
 
 char device[512] = "";		/* Serial device */
 int sflags;
+#ifdef BSD
+struct termios stbuf, svbuf;	/* termios: svbuf=saved, stbuf=set */
+#else
 struct termio stbuf, svbuf;	/* termios: svbuf=saved, stbuf=set */
+#endif
 
 char serial_error[256];
 
@@ -68,7 +79,11 @@
 cleanup_serial(int fd)
 {
   if (fd > 0) {
+#ifdef BSD
+    if (tcsetattr(fd, TCSANOW, &svbuf) < 0 ) {
+#else
     if (ioctl(fd, TCSETA, &svbuf) < 0) {
+#endif
       /* sprintf(serial_error, "Can't ioctl set device %s", device); */
       /* perror(error); */
     }
@@ -86,12 +101,20 @@
     sprintf(serial_error, "%s %s", dev, strerror(errno));
     return(0);
   }
+#ifdef BSD
+  if (tcgetattr(fd, &svbuf) < 0) { /* save settings */
+#else
   if (ioctl(fd, TCGETA, &svbuf) < 0) { /* save settings */
+#endif
     sprintf(serial_error, "%s Can't ioctl TCGETA", dev);
     close(fd);
     return(0);
   }
+#ifdef BSD
+  if (tcsetattr(fd, TCSANOW, &stbuf) < 0) {
+#else
   if (ioctl(fd, TCSETA, &stbuf) < 0) {
+#endif
     sprintf(serial_error, "%s Can't ioctl TCSETA", dev);
     close(fd);
     return(0);
@@ -101,7 +124,11 @@
     return (1);		/* serial port scope found! */
   }
 
+#ifdef BSD
+  if (tcsetattr(fd, TCSANOW, &svbuf) < 0) { /* restore settings */
+#else
   if (ioctl(fd, TCSETA, &svbuf) < 0) { /* restore settings */
+#endif
 #if 0
     sprintf(serial_error, "Can't ioctl (set) %s", dev);
     close(fd);
