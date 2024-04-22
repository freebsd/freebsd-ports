--- MP/code/qcommon/q_platform.h.orig	2019-03-16 18:09:48 UTC
+++ MP/code/qcommon/q_platform.h
@@ -221,14 +221,13 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "i386"
-#elif defined __amd64__
+#if !defined(ARCH_STRING)
+# error ARCH_STRING should be defined by the Makefile
+#endif
+
+#if defined __x86_64__
 #undef idx64
 #define idx64 1
-#define ARCH_STRING "amd64"
-#elif defined __axp__
-#define ARCH_STRING "alpha"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
