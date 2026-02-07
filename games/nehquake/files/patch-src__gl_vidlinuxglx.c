--- ./src/gl_vidlinuxglx.c.orig	Tue Sep 27 19:53:14 2005
+++ ./src/gl_vidlinuxglx.c	Tue May 16 17:36:22 2006
@@ -20,7 +20,9 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
