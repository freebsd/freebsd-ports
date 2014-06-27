--- src/misc/filter-i386.h.orig	2004-06-16 13:32:13.000000000 -0700
+++ src/misc/filter-i386.h	2014-06-21 03:22:13.000000000 -0700
@@ -32,7 +32,16 @@
 
 #include <stdio.h>
 
-extern inline float __mac_g(const float *a, const float *b, unsigned int size)
+#ifdef __OPTIMIZE__
+#define INLINE_EXTERN	static inline
+#else
+#define INLINE_EXTERN	extern
+#endif
+
+INLINE_EXTERN float __mac_g(const float *a, const float *b, unsigned int size)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	float sum = 0;
 	unsigned int i;
@@ -41,8 +50,12 @@
 		sum += (*a++) * (*b++);
 	return sum;
 }
+#endif
 
-extern inline float __mac_c(const float *a, const float *b, unsigned int size)
+INLINE_EXTERN float __mac_c(const float *a, const float *b, unsigned int size)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	float f;
 
@@ -971,6 +984,7 @@
 		return __mac_g(a, b, size);
 	}
 }
+#endif
 
 /* ---------------------------------------------------------------------- */
 #endif				/* _FILTER_I386_H */
