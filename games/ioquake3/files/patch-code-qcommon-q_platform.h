--- code/qcommon/q_platform.h.orig	2009-03-02 17:29:30 UTC
+++ code/qcommon/q_platform.h
@@ -199,8 +199,14 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 
 #ifdef __i386__
 #define ARCH_STRING "i386"
+#elif defined __amd64__
+#define ARCH_STRING "amd64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
+#elif defined __powerpc64__
+#define ARCH_STRING "ppc64"
+#elif defined __powerpc__
+#define ARCH_STRING "ppc"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
