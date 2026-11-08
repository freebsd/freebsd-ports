-- fix bug that __bfloat16 isn't defined
-- guard the immintrin.h include to x86/i386 only, since it is an x86-specific
-- header and unconditionally including it breaks the build on arm64

--- include/simsimd/types.h.orig	2026-03-07 14:05:46 UTC
+++ include/simsimd/types.h
@@ -326,6 +326,10 @@ typedef unsigned short simsimd_f16_t;
 typedef unsigned short simsimd_f16_t;
 #endif
 
+#if defined(__x86_64__) || defined(__i386__)
+#include <immintrin.h>
+#endif
+
 #if !defined(SIMSIMD_NATIVE_BF16) || SIMSIMD_NATIVE_BF16
 /**
  *  @brief  Half-precision brain-float type.
