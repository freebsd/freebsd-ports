--- ngsolve/basiclinalg/expr3.hpp.orig	Sat Oct  2 10:26:56 2004
+++ ngsolve/basiclinalg/expr3.hpp	Tue May 29 19:33:11 2007
@@ -851,6 +851,16 @@
 /**
    Inner product
  */
+inline double InnerProduct ( const double& a, const double& b )
+{
+  return a * b;
+}
+
+inline Complex InnerProduct ( const Complex& a, const Complex b)
+{
+  return a * b;
+}
+
 template <class TA, class TB>
 inline typename TA::TSCAL
 InnerProduct (const MatExpr<TA> & a, const MatExpr<TB> & b)
@@ -862,16 +872,6 @@
   return sum;
 }
 
-inline double InnerProduct (double a, double b)
-{
-  return a * b;
-}
-
-inline Complex InnerProduct (Complex a, Complex b)
-{
-  return a * b;
-}
-
 
 /* **************************** Trace **************************** */
 
@@ -889,16 +889,6 @@
 /* **************************** L2Norm **************************** */
 
 /// Euklidean norm squared
-template <class TA>
-inline double L2Norm2 (const MatExpr<TA> & v)
-{
-  typedef typename TA::TSCAL TSCAL;
-  double sum = 0;
-  for (int i = 0; i < v.Height(); i++)
-    sum += L2Norm2 (v.Spec()(i));  // REval
-  return sum;
-}
-
 
 inline double L2Norm2 (double v)
 {
@@ -908,6 +898,16 @@
 inline double L2Norm2 (Complex v)
 {
   return v.real()*v.real()+v.imag()*v.imag();
+}
+
+template <class TA>
+inline double L2Norm2 (const MatExpr<TA> & v)
+{
+  typedef typename TA::TSCAL TSCAL;
+  double sum = 0;
+  for (int i = 0; i < v.Height(); i++)
+    sum += L2Norm2 (v.Spec()(i));  // REval
+  return sum;
 }
 
 template <class TA>
