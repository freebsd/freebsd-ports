--- thirdparty/pffft/src/simd/pf_altivec_float.h.orig	2026-09-15 18:37:32 UTC
+++ thirdparty/pffft/src/simd/pf_altivec_float.h
@@ -56,8 +56,10 @@ typedef union v4sf_union {
 #  define VADD(a,b) vec_add(a,b)
 #  define VMADD(a,b,c) vec_madd(a,b,c)
 #  define VSUB(a,b) vec_sub(a,b)
-inline v4sf ld_ps1(const float *p) { v4sf v=vec_lde(0,p); return vec_splat(vec_perm(v, v, vec_lvsl(0, p)), 0); }
+static inline v4sf ld_ps1(const float *p) { v4sf v=vec_lde(0,p); return vec_splat(vec_perm(v, v, vec_lvsl(0, p)), 0); }
 #  define LD_PS1(p) ld_ps1(&p)
+#  define VLOAD_UNALIGNED(ptr)  vec_perm(vec_ld(0, ptr), vec_ld(15, ptr), vec_lvsl(0, ptr))
+#  define VLOAD_ALIGNED(ptr)    vec_ld(0, ptr)
 #  define INTERLEAVE2(in1, in2, out1, out2) { v4sf tmp__ = vec_mergeh(in1, in2); out2 = vec_mergel(in1, in2); out1 = tmp__; }
 #  define UNINTERLEAVE2(in1, in2, out1, out2) {                           \
     vector unsigned char vperm1 =  (vector unsigned char){0,1,2,3,8,9,10,11,16,17,18,19,24,25,26,27}; \
@@ -75,6 +77,12 @@ inline v4sf ld_ps1(const float *p) { v4sf v=vec_lde(0,
     x3 = vec_mergel(y1, y3);                    \
   }
 #  define VSWAPHL(a,b) vec_perm(a,b, (vector unsigned char){16,17,18,19,20,21,22,23,8,9,10,11,12,13,14,15})
+
+/* reverse/flip all floats */
+#  define VREV_S(a)    vec_perm(a,a, (vector unsigned char){12,13,14,15,8,9,10,11,4,5,6,7,0,1,2,3})
+/* reverse/flip complex floats */
+#  define VREV_C(a)    vec_perm(a,a, (vector unsigned char){8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7})
+
 #  define VALIGNED(ptr) ((((uintptr_t)(ptr)) & 0xF) == 0)
 
 #endif
