--- ./lib/JAMA/tnt_math_utils.h.orig	2011-03-16 10:47:10.000000000 -0400
+++ ./lib/JAMA/tnt_math_utils.h	2011-03-16 10:51:40.000000000 -0400
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
@@ -56,15 +64,6 @@
 }
 */
 
-/**
-	@returns the absolute value of a real (no-complex) scalar.
-*/
-template <class Real>
-Real abs(const Real &a)
-{
-	return  (a > 0 ? a : -a);
-}
-
 }
 #endif
 /* MATH_UTILS_H */
