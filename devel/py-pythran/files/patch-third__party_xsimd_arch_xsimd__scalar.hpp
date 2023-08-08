--- third_party/xsimd/arch/xsimd_scalar.hpp.orig	2023-04-02 17:04:24 UTC
+++ third_party/xsimd/arch/xsimd_scalar.hpp
@@ -444,11 +444,11 @@ namespace xsimd
 #if defined(_GNU_SOURCE) && !defined(__APPLE__) && !defined(__MINGW32__) && !defined(__ANDROID__)
     inline float exp10(const float& x) noexcept
     {
-        return ::exp10f(x);
+        return ::expf(x*::logf(10));
     }
     inline double exp10(const double& x) noexcept
     {
-        return ::exp10(x);
+        return ::exp(x*::log(10));
     }
 #endif
 
