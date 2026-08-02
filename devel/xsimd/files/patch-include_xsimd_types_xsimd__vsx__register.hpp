--- include/xsimd/types/xsimd_vsx_register.hpp.orig	2026-08-01 20:31:20 UTC
+++ include/xsimd/types/xsimd_vsx_register.hpp
@@ -64,10 +64,10 @@ namespace xsimd
         XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(short, short);
         XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(unsigned int, int);
         XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(int, int);
-        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(unsigned long, long);
-        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(long, long);
+        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(unsigned long, long long);
+        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(long, long long);
         XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(float, int);
-        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(double, long);
+        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(double, long long);
 
 #undef XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER
     }
