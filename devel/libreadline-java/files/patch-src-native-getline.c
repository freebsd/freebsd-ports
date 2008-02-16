--- src/native/getline.c	2003-01-07 11:14:35.000000000 +0100
+++ /tmp/libreadline-java-0.8.0/src/native/getline.c	2007-09-22 22:20:06.000000000 +0200
@@ -136,7 +136,6 @@
 #ifndef __convexc__
 extern int      read();
 extern int      kill();
-extern int      ioctl();
 #endif /* not __convexc__ */
 #ifdef POSIX		/* use POSIX interface */
 #include <termios.h>
