--- dnn/vec_neon.h.orig	2024-03-12 15:41:06 UTC
+++ dnn/vec_neon.h
@@ -34,7 +34,7 @@
 #include <arm_neon.h>
 #include "os_support.h"
 
-#if defined(__arm__) && !defined(__aarch64__)
+#if __ARM_ARCH < 8
 /* Emulate vcvtnq_s32_f32() for ARMv7 Neon. */
 static OPUS_INLINE int32x4_t vcvtnq_s32_f32(float32x4_t x) {
   return vrshrq_n_s32(vcvtq_n_s32_f32(x, 8), 8);
