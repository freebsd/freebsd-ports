--- vid_glx.c.orig	Thu Aug 28 18:08:22 2003
+++ vid_glx.c	Thu Aug 28 18:08:03 2003
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
