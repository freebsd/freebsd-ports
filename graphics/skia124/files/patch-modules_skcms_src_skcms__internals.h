--- modules/skcms/src/skcms_internals.h.orig	2024-06-11 14:20:28 UTC
+++ modules/skcms/src/skcms_internals.h
@@ -39,6 +39,8 @@ extern "C" {
         // - Clang 18 runs into an ICE on armv7/androideabi with [[clang::musttail]].
         //   (http://crbug.com/1504548)
         // - Android RISC-V also runs into an ICE (b/314692534)
+        // - So does Linux ppc64le (https://github.com/llvm/llvm-project/issues/108014,
+        //   https://github.com/llvm/llvm-project/issues/98859)
         // - LoongArch developers indicate they had to turn it off
         // - Windows builds generate incorrect code with [[clang::musttail]] and crash mysteriously.
         //   (http://crbug.com/1505442)
@@ -47,6 +49,7 @@ extern "C" {
                                                  && !defined(__EMSCRIPTEN__) \
                                                  && !defined(__arm__) \
                                                  && !defined(__riscv) \
+                                                 && !defined(__powerpc__) \
                                                  && !defined(__loongarch__) \
                                                  && !defined(_WIN32) && !defined(__SYMBIAN32__)
             #define SKCMS_HAS_MUSTTAIL 1
