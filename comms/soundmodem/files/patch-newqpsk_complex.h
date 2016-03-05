--- newqpsk/complex.h.orig	2015-05-04 17:51:16 UTC
+++ newqpsk/complex.h
@@ -10,11 +10,15 @@ typedef struct {
 #endif
 } complex;
 
+#if __clang__ > 0
+#define only_inline inline
+#else
 #if __GNUC__ < 5
 #define only_inline extern inline
 #else
 #define only_inline inline
 #endif
+#endif
 
 /*
  * Complex multiplication.
