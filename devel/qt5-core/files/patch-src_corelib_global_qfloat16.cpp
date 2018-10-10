global/qfloat16.cpp:149:31: error: use of undeclared identifier 'vcvt_f16_f32'
        vst1_f16(out_f16 + i, vcvt_f16_f32(vld1q_f32(in + i)));
                              ^
global/qfloat16.cpp:159:28: error: use of undeclared identifier 'vcvt_f32_f16'
        vst1q_f32(out + i, vcvt_f32_f16(vld1_f16(in_f16 + i)));
                           ^

--- src/corelib/global/qfloat16.cpp.orig	2018-06-15 07:29:31 UTC
+++ src/corelib/global/qfloat16.cpp
@@ -135,7 +135,7 @@ f16cextern void qFloatFromFloat16_fast(float *out, con
 #undef f16cextern
 }
 
-#elif defined(__ARM_FP16_FORMAT_IEEE) && defined(__ARM_NEON__)
+#elif defined(__ARM_FP16_FORMAT_IEEE) && defined(__ARM_NEON__) && (__ARM_FP & 2)
 static inline bool hasFastF16()
 {
     return true;
