--- src/utils/xrMiscMath/vector.cpp.orig	2026-09-30 22:31:46 UTC
+++ src/utils/xrMiscMath/vector.cpp
@@ -140,7 +140,7 @@ float angle_inertion_var(float src, float tgt, float m
 	return src;
 }
 
-double rsqrt(double v) noexcept { return 1.0 / _sqrt(v); }
+double xr_rsqrt(double v) noexcept { return 1.0 / _sqrt(v); }
 
 //////////////////////////////////////////////////////////////////
 
