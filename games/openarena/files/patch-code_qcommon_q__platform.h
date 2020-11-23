--- code/qcommon/q_platform.h.orig	2020-11-23 13:12:36 UTC
+++ code/qcommon/q_platform.h
@@ -235,6 +235,8 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #define ARCH_STRING "amd64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
+#elif defined __powerpc64__
+#define ARCH_STRING "ppc64"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
