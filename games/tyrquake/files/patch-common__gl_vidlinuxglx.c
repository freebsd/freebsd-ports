--- ./common/gl_vidlinuxglx.c.orig	Sat Feb 18 19:19:32 2006
+++ ./common/gl_vidlinuxglx.c	Sun May 14 16:20:57 2006
@@ -21,7 +21,9 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
