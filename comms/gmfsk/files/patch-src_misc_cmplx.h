--- src/misc/cmplx.h.orig	2004-06-22 14:43:31.000000000 -0700
+++ src/misc/cmplx.h	2014-06-21 03:17:56.000000000 -0700
@@ -40,10 +40,19 @@
 
 typedef fftw_complex complex;
 
+#ifdef __OPTIMIZE__
+#define INLINE_EXTERN	static inline
+#else
+#define INLINE_EXTERN	extern
+#endif
+
 /*
  * Complex multiplication.
  */
-extern __inline__ complex cmul(complex x, complex y)
+INLINE_EXTERN  complex cmul(complex x, complex y)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	complex z;
 
@@ -52,11 +61,15 @@
 
 	return z;
 }
+#endif
 
 /*
  * Complex addition.
  */
-extern __inline__ complex cadd(complex x, complex y)
+INLINE_EXTERN  complex cadd(complex x, complex y)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	complex z;
 
@@ -65,11 +78,15 @@
 
 	return z;
 }
+#endif
 
 /*
  * Complex subtraction.
  */
-extern __inline__ complex csub(complex x, complex y)
+INLINE_EXTERN  complex csub(complex x, complex y)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	complex z;
 
@@ -78,11 +95,15 @@
 
 	return z;
 }
+#endif
 
 /*
  * Complex multiply-accumulate.
  */
-extern __inline__ complex cmac(complex *a, complex *b, int ptr, int len)
+INLINE_EXTERN  complex cmac(complex *a, complex *b, int ptr, int len)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	complex z;
 	int i;
@@ -99,12 +120,16 @@
 
 	return z;
 }
+#endif
 
 /*
  * Complex ... yeah, what??? Returns a complex number that has the
  * properties: |z| = |x| * |y|  and  arg(z) = arg(y) - arg(x)
  */
-extern __inline__ complex ccor(complex x, complex y)
+INLINE_EXTERN  complex ccor(complex x, complex y)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	complex z;
 
@@ -113,51 +138,75 @@
 
 	return z;
 }
+#endif
 
 /*
  * Real part of the complex ???
  */
-extern __inline__ double ccorI(complex x, complex y)
+INLINE_EXTERN  double ccorI(complex x, complex y)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return c_re(x) * c_re(y) + c_im(x) * c_im(y);
 }
+#endif
 
 /*
  * Imaginary part of the complex ???
  */
-extern __inline__ double ccorQ(complex x, complex y)
+INLINE_EXTERN  double ccorQ(complex x, complex y)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return c_re(x) * c_im(y) - c_im(x) * c_re(y);
 }
+#endif
 
 /*
  * Modulo (absolute value) of a complex number.
  */
-extern __inline__ double cmod(complex x)
+INLINE_EXTERN  double cmod(complex x)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return sqrt(c_re(x) * c_re(x) + c_im(x) * c_im(x));
 }
+#endif
 
 /*
  * Square of the absolute value (power).
  */
-extern __inline__ double cpwr(complex x)
+INLINE_EXTERN  double cpwr(complex x)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return (c_re(x) * c_re(x) + c_im(x) * c_im(x));
 }
+#endif
 
 /*
  * Argument of a complex number.
  */
-extern __inline__ double carg(complex x)
+INLINE_EXTERN  double carg(complex x)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	return atan2(c_im(x), c_re(x));
 }
+#endif
 
 /*
  * Complex square root.
  */
-extern __inline__ complex csqrt(complex x)
+INLINE_EXTERN  complex csqrt(complex x)
+#ifndef __OPTIMIZE__
+;
+#else
 {
 	complex z;
 
@@ -166,5 +215,6 @@
 
 	return z;
 }
+#endif
 
 #endif
