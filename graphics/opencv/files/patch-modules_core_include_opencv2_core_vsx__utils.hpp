--- modules/core/include/opencv2/core/vsx_utils.hpp.orig	2022-03-21 01:40:15 UTC
+++ modules/core/include/opencv2/core/vsx_utils.hpp
@@ -324,6 +324,7 @@ VSX_IMPL_1RG(vec_udword2, vec_float4,  xvcvspuxds, vec
 #define VSX_IMPL_CONVERT(rt, rg, fnm) \
 VSX_FINLINE(rt) fnm(const rg& a) { return __builtin_convertvector(a, rt); }
 
+#ifndef vec_permi
 #if __clang_major__ < 5
 // implement vec_permi in a dirty way
 #   define VSX_IMPL_CLANG_4_PERMI(Tvec)                                                 \
@@ -351,12 +352,14 @@ VSX_FINLINE(rt) fnm(const rg& a) { return __builtin_co
 // vec_xxpermdi is missing little-endian supports in clang 4 just like gcc4
 #   define vec_permi(a, b, c) vec_xxpermdi(b, a, (3 ^ (((c) & 1) << 1 | (c) >> 1)))
 #endif // __clang_major__ < 5
+#endif // vec_permi
 
 // shift left double by word immediate
 #ifndef vec_sldw
 #   define vec_sldw vec_xxsldwi
 #endif
 
+#if __clang_major__ < 13
 // Implement vec_rsqrt since clang only supports vec_rsqrte
 #ifndef vec_rsqrt
     VSX_FINLINE(vec_float4) vec_rsqrt(const vec_float4& a)
@@ -380,6 +383,7 @@ VSX_FINLINE(vec_udword2) vec_promote(unsigned long lon
     ret[b & 1] = a;
     return ret;
 }
+#endif
 
 // vec_popcnt should return unsigned but clang has different thought just like gcc in vec_vpopcnt
 #define VSX_IMPL_POPCNTU(Tvec, Tvec2, ucast)   \
