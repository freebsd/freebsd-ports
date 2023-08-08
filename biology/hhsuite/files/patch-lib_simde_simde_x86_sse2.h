--- lib/simde/simde/x86/sse2.h.orig	2022-10-01 09:24:35 UTC
+++ lib/simde/simde/x86/sse2.h
@@ -6591,7 +6591,7 @@ simde_x_mm_negate_pd(simde__m128d a) {
 
     #if defined(SIMDE_POWER_ALTIVEC_P9_NATIVE)
       r_.altivec_f64 = vec_neg(a_.altivec_f64);
-    #elif defined(SIMDE_ARM_NEON_A32V7_NATIVE)
+    #elif defined(SIMDE_ARM_NEON_A64V8_NATIVE)
       r_.neon_f64 = vnegq_f64(a_.neon_f64);
     #elif defined(SIMDE_WASM_SIMD128d_NATIVE)
       r_.wasm_v128d = wasm_f64x2_neg(a_.wasm_v128d);
