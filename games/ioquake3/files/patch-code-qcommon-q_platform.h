--- code/qcommon/q_platform.h.orig	2009-03-02 17:29:30 UTC
+++ code/qcommon/q_platform.h
@@ -199,6 +199,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 #ifdef __i386__
 #define ARCH_STRING "i386"
+#elif defined __amd64__
+#define ARCH_STRING "amd64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
 #endif
