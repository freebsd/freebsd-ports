--- lib-src/libnyquist/sys/term.c.orig	Tue Dec  2 19:17:30 2003
+++ lib-src/libnyquist/sys/term.c	Tue Dec  2 19:17:51 2003
@@ -40,7 +40,7 @@
 #else
 
 #include <termios.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <asm/ioctls.h>
 #endif
 #include <signal.h>
