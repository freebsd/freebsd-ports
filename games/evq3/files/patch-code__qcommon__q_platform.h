--- ./code/qcommon/q_platform.h.orig	2008-06-11 18:33:07.000000000 -0300
+++ ./code/qcommon/q_platform.h	2008-06-27 20:26:36.000000000 -0300
@@ -194,11 +194,7 @@
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "i386"
-#elif defined __axp__
-#define ARCH_STRING "alpha"
-#endif
+#define ARCH_STRING ARCH
 
 #if BYTE_ORDER == BIG_ENDIAN
 #define Q3_BIG_ENDIAN
