--- ./vid_glx.c.orig	Thu Apr  6 20:23:19 2006
+++ ./vid_glx.c	Tue Aug 29 20:59:12 2006
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
