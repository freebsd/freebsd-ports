--- sys/unix/term.c.orig	2021-04-18 05:56:28 UTC
+++ sys/unix/term.c
@@ -10,7 +10,7 @@
 
 
 #include <termios.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <asm/ioctls.h>
 #endif
 #include <sys/ioctl.h>
