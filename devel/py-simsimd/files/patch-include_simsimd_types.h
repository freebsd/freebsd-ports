-- fix bug that __bfloat16 isn't defined

--- include/simsimd/types.h.orig	2026-08-02 22:31:43 UTC
+++ include/simsimd/types.h
@@ -326,6 +326,8 @@ typedef unsigned short simsimd_f16_t;
 typedef unsigned short simsimd_f16_t;
 #endif
 
+#include <immintrin.h>
+
 #if !defined(SIMSIMD_NATIVE_BF16) || SIMSIMD_NATIVE_BF16
 /**
  *  @brief  Half-precision brain-float type.
