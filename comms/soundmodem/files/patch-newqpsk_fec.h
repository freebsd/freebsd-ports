--- newqpsk/fec.h.orig	2015-05-04 17:49:44 UTC
+++ newqpsk/fec.h
@@ -3,11 +3,15 @@
 
 /* --------------------------------------------------------------------- */
 
+#if __clang__ > 0
+#define only_inline inline
+#else
 #if __GNUC__ < 5
 #define only_inline extern inline
 #else
 #define only_inline inline
 #endif
+#endif
 
 struct fecstate {
 	int feclevel;
