--- code/qcommon/q_platform.h.orig	2009-08-30 19:30:01.000000000 +0200
+++ code/qcommon/q_platform.h	2009-08-30 19:28:38.000000000 +0200
@@ -199,6 +199,8 @@
 
 #ifdef __i386__
 #define ARCH_STRING "i386"
+#elif defined __amd64__
+#define ARCH_STRING "x86_64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
 #endif
