--- lib/JAMA/tnt_math_utils.h.orig	Sat Sep 30 19:34:43 2006
+++ lib/JAMA/tnt_math_utils.h	Sat Sep 30 19:36:07 2006
@@ -20,6 +20,14 @@
 namespace TNT
 {
 /**
+	@returns the absolute value of a real (no-complex) scalar.
+*/
+template <class Real>
+Real abs(const Real &a)
+{
+	return  (a > 0 ? a : -a);
+}
+/**
 	@returns hypotenuse of real (non-complex) scalars a and b by 
 	avoiding underflow/overflow
 	using (a * sqrt( 1 + (b/a) * (b/a))), rather than
@@ -55,15 +63,6 @@
 	return  a > b ? a : b;
 }
 */
-
-/**
-	@returns the absolute value of a real (no-complex) scalar.
-*/
-template <class Real>
-Real abs(const Real &a)
-{
-	return  (a > 0 ? a : -a);
-}
 
 }
 #endif
