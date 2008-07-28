--- ser_unix.c.orig	2008-03-29 20:34:36.000000000 -0400
+++ ser_unix.c	2008-03-29 20:53:04.000000000 -0400
@@ -13,7 +13,14 @@
 #include <stdlib.h>
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
@@ -23,7 +30,11 @@
 
 char device[512] = "";		/* Serial device */
 int sflags;
+#ifdef BSD
+struct termios stbuf, svbuf;	/* termios: svbuf=saved, stbuf=set */
+#else
 struct termio stbuf, svbuf;	/* termios: svbuf=saved, stbuf=set */
+#endif
 
 /* return a single byte from the serial device or return -1 if none avail. */
 int
@@ -65,7 +76,11 @@
 cleanup_serial(int fd)
 {
   if (fd > 0) {
+#ifdef BSD
+    if (tcgetattr(fd, &svbuf) < 0 ) {
+#else
     if (ioctl(fd, TCSETA, &svbuf) < 0) {
+#endif
       sprintf(error, "%s: can't ioctl set device %s", progname, device);
       perror(error);
     }
@@ -84,13 +99,21 @@
     perror(error);
     return(0);
   }
+#ifdef BSD
+  if (tcgetattr(fd, &svbuf) < 0) { /* save settings */
+#else
   if (ioctl(fd, TCGETA, &svbuf) < 0) { /* save settings */
+#endif
     sprintf(error, "%s: can't ioctl get device %s", progname, dev);
     perror(error);
     close(fd);
     return(0);
   }
+#ifdef BSD
+  if (tcsetattr(fd, TCSANOW, &stbuf) < 0) {
+#else
   if (ioctl(fd, TCSETA, &stbuf) < 0) {
+#endif
     sprintf(error, "%s: can't ioctl set device %s", progname, dev);
     perror(error);
     close(fd);
@@ -101,7 +124,11 @@
     return (1);		/* serial port scope found! */
   }
 
+#ifdef BSD
+  if (tcsetattr(fd, TCSANOW, &svbuf) < 0) { /* restore settings */
+#else
   if (ioctl(fd, TCSETA, &svbuf) < 0) { /* restore settings */
+#endif
     sprintf(error, "%s: can't ioctl set device %s", progname, dev);
     perror(error);
     close(fd);
