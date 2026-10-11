--- src/utils/xrMiscMath/xrMiscMath.cpp.orig	2026-09-30 22:31:46 UTC
+++ src/utils/xrMiscMath/xrMiscMath.cpp
@@ -8,7 +8,7 @@ bool exact_normalize(float* a)
 	double epsilon = 1.192092896e-05F;
 	if (sqr_magnitude > epsilon)
 	{
-		double l = rsqrt(sqr_magnitude);
+		double l = xr_rsqrt(sqr_magnitude);
 		a[0] *= l;
 		a[1] *= l;
 		a[2] *= l;
@@ -31,7 +31,7 @@ bool exact_normalize(float* a)
 		{
 			a0 /= aa1;
 			a2 /= aa1;
-			l = rsqrt(a0*a0 + a2*a2 + 1);
+			l = xr_rsqrt(a0*a0 + a2*a2 + 1);
 			a[0] = a0*l;
 			a[1] = (double)_copysign(l, a1);
 			a[2] = a2*l;
@@ -44,7 +44,7 @@ bool exact_normalize(float* a)
 		aa2_largest: // aa2 is largest
 			a0 /= aa2;
 			a1 /= aa2;
-			l = rsqrt(a0*a0 + a1*a1 + 1);
+			l = xr_rsqrt(a0*a0 + a1*a1 + 1);
 			a[0] = a0*l;
 			a[1] = a1*l;
 			a[2] = (double)_copysign(l, a2);
@@ -61,7 +61,7 @@ bool exact_normalize(float* a)
 			}
 			a1 /= aa0;
 			a2 /= aa0;
-			l = rsqrt(a1*a1 + a2*a2 + 1);
+			l = xr_rsqrt(a1*a1 + a2*a2 + 1);
 			a[0] = (double)_copysign(l, a0);
 			a[1] = a1*l;
 			a[2] = a2*l;
