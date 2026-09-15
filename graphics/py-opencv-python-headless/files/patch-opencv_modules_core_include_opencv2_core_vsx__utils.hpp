--- opencv/modules/core/include/opencv2/core/vsx_utils.hpp.orig	2026-09-15 18:33:59 UTC
+++ opencv/modules/core/include/opencv2/core/vsx_utils.hpp
@@ -418,6 +418,10 @@ VSX_REDIRECT_1RG(vec_udword2, vec_udword2, vec_popcntu
 VSX_REDIRECT_1RG(vec_uint4,   vec_uint4,   vec_popcntu, vec_popcnt)
 VSX_REDIRECT_1RG(vec_udword2, vec_udword2, vec_popcntu, vec_popcnt)
 
+// converts between single and double precision
+VSX_REDIRECT_1RG(vec_float4,  vec_double2, vec_cvfo, __builtin_vsx_xvcvdpsp)
+VSX_REDIRECT_1RG(vec_double2, vec_float4,  vec_cvfo, __builtin_vsx_xvcvspdp)
+
 // converts word and doubleword to double-precision
 #ifdef vec_ctd
 #   undef vec_ctd
