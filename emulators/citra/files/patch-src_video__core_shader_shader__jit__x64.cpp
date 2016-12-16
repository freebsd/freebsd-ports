#include <smmintrin.h> fails without -msse4.1 on Clang < 3.8

https://github.com/llvm-mirror/clang/commit/41885d36e85ead75a1d18ef7d2f43663f90ed67e

--- src/video_core/shader/shader_jit_x64.cpp.orig	2016-12-16 05:41:22 UTC
+++ src/video_core/shader/shader_jit_x64.cpp
@@ -6,7 +6,6 @@
 #include <cmath>
 #include <cstdint>
 #include <nihstro/shader_bytecode.h>
-#include <smmintrin.h>
 #include <xmmintrin.h>
 #include "common/assert.h"
 #include "common/logging/log.h"
@@ -499,7 +498,7 @@ void JitShader::Compile_FLR(Instruction 
     Compile_SwizzleSrc(instr, 1, instr.common.src1, SRC1);
 
     if (Common::GetCPUCaps().sse4_1) {
-        roundps(SRC1, SRC1, _MM_FROUND_FLOOR);
+        roundps(SRC1, SRC1, Gen::FROUND_FLOOR);
     } else {
         cvttps2dq(SRC1, SRC1);
         cvtdq2ps(SRC1, SRC1);
