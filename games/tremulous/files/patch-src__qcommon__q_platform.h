--- ./tremulous-1.1.0-src/src/qcommon/q_platform.h.orig	Fri Jan 13 22:12:32 2006
+++ ./tremulous-1.1.0-src/src/qcommon/q_platform.h	Wed Jun  7 16:57:12 2006
@@ -177,11 +177,7 @@
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "x86"
-#elif defined __axp__
-#define ARCH_STRING "alpha"
-#endif
+#define ARCH_STRING ARCH
 
 #if BYTE_ORDER == BIG_ENDIAN
 #define Q3_BIG_ENDIAN
