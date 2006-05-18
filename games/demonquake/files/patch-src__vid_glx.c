--- ./src/vid_glx.c.orig	Thu Nov  3 17:12:46 2005
+++ ./src/vid_glx.c	Tue May 16 14:33:39 2006
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
