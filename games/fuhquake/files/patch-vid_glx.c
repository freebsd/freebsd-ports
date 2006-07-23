--- vid_glx.c.orig	Wed Jan  7 00:39:44 2004
+++ vid_glx.c	Sun Jan 22 22:07:23 2006
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
