--- src/misc/filter.h.orig	2004-04-13 05:43:45.000000000 -0700
+++ src/misc/filter.h	2014-06-21 03:16:02.000000000 -0700
@@ -39,7 +39,10 @@
 
 
 #ifndef __HAVE_ARCH_MAC
-extern __inline__ float mac(const float *a, const float *b, unsigned int size)
+INLINE_EXTERN float mac(const float *a, const float *b, unsigned int size)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	float sum = 0;
 	unsigned int i;
@@ -48,6 +51,7 @@
 		sum += (*a++) * (*b++);
 	return sum;
 }
+#endif
 #endif				/* __HAVE_ARCH_MAC */
 
 #endif				/* __OPTIMIZE__ */
