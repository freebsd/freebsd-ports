--- quickjs-libc.c.orig	2020-04-12 13:18:13 UTC
+++ quickjs-libc.c
@@ -45,9 +45,13 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/wait.h>
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 typedef sig_t sighandler_t;
 #endif
+#endif
+
+#if defined(__FreeBSD__)
+extern char **environ;
 #endif
 
 #include "cutils.h"
