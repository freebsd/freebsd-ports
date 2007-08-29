--- d2c/runtime/c-code/float.c	Wed Jul 23 08:08:58 2003
+++ d2c/runtime/c-code/float.c	Tue Aug 21 14:43:47 2007
@@ -101,11 +101,11 @@
 
 #define SQRTHL	0.70710678118654752440L
 
+static long double polevll(long double, long double *, size_t);
+static long double p1evll(long double, long double *, size_t);
+
 long double (logl)(long double x)
 {
-  static long double polevll(long double, long double *, size_t);
-  static long double p1evll(long double, long double *, size_t);
-
   /* Coefficients for log(1+x) = x - x**2/2 + x**3 P(x)/Q(x) 1/sqrt(2) <= x <
    * sqrt(2) Theoretical peak relative error = 2.32e-20
    */
@@ -229,11 +229,11 @@
 #define LOG2EAL	4.4269504088896340735992e-1L
 #define SQRTHL	0.70710678118654752440L
 
+long double polevll(long double, long double *, size_t);
+long double p1evll(long double, long double *, size_t);
+
 long double (log2l)(long double x)
 {
-  static long double polevll(long double, long double *, size_t);
-  static long double p1evll(long double, long double *, size_t);
-
   static long double P[] = {
     4.9962495940332550844739E-1L,
     1.0767376367209449010438E1L,
@@ -362,11 +362,11 @@
 
 #define SQRTHL	0.70710678118654752440L
 
+static long double polevll(long double, long double *, size_t);
+static long double p1evll(long double, long double *, size_t);
+
 long double (log10l)(long double x)
 {
-  static long double polevll(long double, long double *, size_t);
-  static long double p1evll(long double, long double *, size_t);
-
   /* Coefficients for log(1+x) = x - x**2/2 + x**3 P(x)/Q(x) 1/sqrt(2) <= x <
    * sqrt(2) Theoretical peak relative error = 6.2e-22
    */
@@ -497,11 +497,11 @@
 #define LOG2EA	0.44269504088896340735992	/* log2(e) - 1 */
 #define SQRTH	0.70710678118654752440
 
+static double polevl(double, double *, size_t);
+static double p1evl(double, double *, size_t);
+
 double (log2)(double x)
 {
-  static double polevl(double, double *, size_t);
-  static double p1evl(double, double *, size_t);
-
   /* Coefficients for log(1+x) = x - x**2/2 + x**3 P(x)/Q(x) 1/sqrt(2) <= x <
    * sqrt(2)
    */


