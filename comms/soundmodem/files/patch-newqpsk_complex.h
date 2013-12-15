--- newqpsk/complex.h.orig	2008-12-14 09:47:34.000000000 -0500
+++ newqpsk/complex.h	2013-12-14 17:54:58.000000000 -0500
@@ -13,7 +13,7 @@
 /*
  * Complex multiplication.
  */
-extern __inline__ complex cmul(complex x, complex y)
+static __inline__ complex cmul(complex x, complex y)
 {
 	complex z;
 
@@ -27,7 +27,7 @@
  * Complex ... yeah, what??? Returns a complex number that has the
  * properties: |z| = |x| * |y|  and  arg(z) = arg(y) - arg(x)
  */
-extern __inline__ complex ccor(complex x, complex y)
+static __inline__ complex ccor(complex x, complex y)
 {
 	complex z;
 
@@ -40,7 +40,7 @@
 /*
  * Real part of the complex ???
  */
-extern __inline__ float ccorI(complex x, complex y)
+static __inline__ float ccorI(complex x, complex y)
 {
 	return x.re * y.re + x.im * y.im;
 }
@@ -48,7 +48,7 @@
 /*
  * Imaginary part of the complex ???
  */
-extern __inline__ float ccorQ(complex x, complex y)
+static __inline__ float ccorQ(complex x, complex y)
 {
 	return x.re * y.im - x.im * y.re;
 }
@@ -56,7 +56,7 @@
 /*
  * Modulo (absolute value) of a complex number.
  */
-extern __inline__ float cmod(complex x)
+static __inline__ float cmod(complex x)
 {
 	return sqrt(x.re * x.re + x.im * x.im);
 }
@@ -64,7 +64,7 @@
 /*
  * Square of the absolute value (power).
  */
-extern __inline__ float cpwr(complex x)
+static __inline__ float cpwr(complex x)
 {
 	return (x.re * x.re + x.im * x.im);
 }
@@ -72,7 +72,7 @@
 /*
  * Argument of a complex number.
  */
-extern __inline__ float carg(complex x)
+static __inline__ float carg(complex x)
 {
 	return atan2(x.im, x.re);
 }
