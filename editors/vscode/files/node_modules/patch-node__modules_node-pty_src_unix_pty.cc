--- node_modules/node-pty/src/unix/pty.cc.orig	2024-09-09 06:45:53 UTC
+++ node_modules/node-pty/src/unix/pty.cc
@@ -66,6 +66,11 @@
 #include <termios.h>
 #endif
 
+/* for termios */
+#if defined(__FreeBSD__)
+#include <termios.h>
+#endif
+
 /* NSIG - macro for highest signal + 1, should be defined */
 #ifndef NSIG
 #define NSIG 32
