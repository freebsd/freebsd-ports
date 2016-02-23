--- newqpsk/misc.h.orig	2015-05-04 17:50:51 UTC
+++ newqpsk/misc.h
@@ -5,11 +5,15 @@
 #define M_PI 3.14159265358979323846
 #endif
 
+#if __clang__ > 0
+#define only_inline inline
+#else
 #if __GNUC__ < 5
 #define only_inline extern inline
 #else
 #define only_inline inline
 #endif
+#endif
 
 /* ---------------------------------------------------------------------- */
 
