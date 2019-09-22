--- quickjs-libc.c.orig	2019-09-18 18:34:20 UTC
+++ quickjs-libc.c
@@ -45,7 +45,7 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/wait.h>
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 typedef sig_t sighandler_t;
 #endif
 #endif
