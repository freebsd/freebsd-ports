https://github.com/llvm-mirror/clang/commit/41885d36e85ead75a1d18ef7d2f43663f90ed67e

--- src/video_core/shader/shader_jit_x64_compiler.cpp.orig	2017-02-21 21:47:34 UTC
+++ src/video_core/shader/shader_jit_x64_compiler.cpp
@@ -6,7 +6,12 @@
 #include <cmath>
 #include <cstdint>
 #include <nihstro/shader_bytecode.h>
+#if defined(__clang__) && (__clang_major__ == 3 && __clang_minor__ < 8)
+// <smmintrin.h> requires -msse4.1 with Clang before 3.8
+#define _MM_FROUND_FLOOR 0x01
+#else
 #include <smmintrin.h>
+#endif
 #include <xmmintrin.h>
 #include "common/assert.h"
 #include "common/logging/log.h"
