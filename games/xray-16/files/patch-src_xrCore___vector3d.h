--- src/xrCore/_vector3d.h.orig	2026-09-30 22:31:46 UTC
+++ src/xrCore/_vector3d.h
@@ -356,7 +356,7 @@ bool _valid(const _vector3<T>& v)
 //////////////////////////////////////////////////////////////////////////
 #pragma warning(push)
 #pragma warning(disable : 4244)
-double rsqrt(double v) noexcept;
+double xr_rsqrt(double v) noexcept;
 bool exact_normalize(float* a);
 bool exact_normalize(Fvector3& a);
 #pragma warning(pop)
