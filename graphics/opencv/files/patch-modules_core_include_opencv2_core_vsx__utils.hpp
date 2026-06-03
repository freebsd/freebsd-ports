--- modules/core/include/opencv2/core/vsx_utils.hpp.orig	2025-12-30 07:52:05 UTC
+++ modules/core/include/opencv2/core/vsx_utils.hpp
@@ -258,7 +258,7 @@ VSX_IMPL_1VRG(vec_udword2, vec_dword2,  vpopcntd, vec_
 
 // converts between single and double-precision
 // vec_floate and vec_doubleo are available since Power10 and z14
-#if defined(__POWER10__) || (defined(__powerpc64__) && defined(__ARCH_PWR10__)
+#if defined(__POWER10__) || (defined(__powerpc64__) && defined(__ARCH_PWR10__))
 //  Use VSX double<->float conversion instructions (if supported by the architecture)
     VSX_REDIRECT_1RG(vec_float4,  vec_double2, vec_cvfo, vec_floate)
     VSX_REDIRECT_1RG(vec_double2, vec_float4,  vec_cvfo, vec_doubleo)
@@ -417,6 +417,10 @@ VSX_REDIRECT_1RG(vec_udword2, vec_udword2, vec_popcntu
 VSX_REDIRECT_1RG(vec_ushort8, vec_ushort8, vec_popcntu, vec_popcnt)
 VSX_REDIRECT_1RG(vec_uint4,   vec_uint4,   vec_popcntu, vec_popcnt)
 VSX_REDIRECT_1RG(vec_udword2, vec_udword2, vec_popcntu, vec_popcnt)
+
+// converts between single and double precision
+VSX_REDIRECT_1RG(vec_float4,  vec_double2, vec_cvfo, __builtin_vsx_xvcvdpsp)
+VSX_REDIRECT_1RG(vec_double2, vec_float4,  vec_cvfo, __builtin_vsx_xvcvspdp)
 
 // converts word and doubleword to double-precision
 #ifdef vec_ctd
