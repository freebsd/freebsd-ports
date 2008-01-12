--- ./code/qcommon/q_platform.h.orig	Tue Dec 27 16:46:01 2005
+++ ./code/qcommon/q_platform.h	Sun Jun 11 17:26:26 2006
@@ -176,11 +176,7 @@
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
