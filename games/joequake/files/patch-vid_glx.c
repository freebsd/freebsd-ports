--- ./vid_glx.c.orig	Sun Jan  8 18:36:04 2006
+++ ./vid_glx.c	Sat May 20 10:00:24 2006
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
