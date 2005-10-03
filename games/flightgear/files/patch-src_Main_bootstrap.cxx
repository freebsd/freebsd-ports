--- src/Main/bootstrap.cxx.orig	Thu Sep 15 20:48:39 2005
+++ src/Main/bootstrap.cxx	Thu Sep 15 20:51:05 2005
@@ -28,6 +28,8 @@
 #if defined(__linux__) && defined(__i386__)
 #  include <fpu_control.h>
 #  include <signal.h>
+#elif defined(__FreeBSD__)
+#  include <signal.h>
 #endif
 
 #include <stdlib.h>
@@ -144,6 +146,8 @@
     // Enable floating-point exceptions for Linux/x86
 #if defined(__linux__) && defined(__i386__)
     initFPE();
+#elif defined(__FreeBSD__)
+    signal(SIGFPE, SIG_IGN);
 #endif
 
 #if defined(sgi)
