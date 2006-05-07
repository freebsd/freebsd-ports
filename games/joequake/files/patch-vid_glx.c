--- vid_glx.c.orig	Sun Oct 16 17:40:58 2005
+++ vid_glx.c	Mon Dec  5 21:10:31 2005
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
