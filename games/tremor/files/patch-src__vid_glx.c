--- ./src/vid_glx.c.orig	Thu Nov 10 07:03:04 2005
+++ ./src/vid_glx.c	Tue May 16 14:59:52 2006
@@ -22,7 +22,9 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
