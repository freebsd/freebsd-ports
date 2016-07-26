--- lib/JAMA/tnt_math_utils.h.orig	2016-07-26 15:10:24 UTC
+++ lib/JAMA/tnt_math_utils.h
@@ -20,6 +20,14 @@ inline const _Tp& max(const _Tp& __a, co
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
@@ -56,15 +64,6 @@ Scalar max(const Scalar &a, const Scalar
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
