--- SP/code/qcommon/q_platform.h.orig	2019-03-16 18:09:48 UTC
+++ SP/code/qcommon/q_platform.h
@@ -35,11 +35,7 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 
 #else
 
-#if (defined _M_IX86 || defined __i386__) && !defined(C_ONLY)
-#define id386 1
-#else
 #define id386 0
-#endif
 
 #if (defined(powerc) || defined(powerpc) || defined(ppc) || \
 	defined(__ppc) || defined(__ppc__)) && !defined(C_ONLY)
@@ -224,11 +220,13 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #ifdef __i386__
 #define ARCH_STRING "i386"
 #elif defined __amd64__
-#undef idx64
-#define idx64 1
 #define ARCH_STRING "amd64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
+#elif defined __powerpc64__
+#define ARCH_STRING "powerpc64"
+#elif defined __powerpc__
+#define ARCH_STRING "powerpc"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
