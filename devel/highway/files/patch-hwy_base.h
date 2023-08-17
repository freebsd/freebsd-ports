https://github.com/google/highway/issues/1658

--- hwy/base.h.orig	2023-08-11 13:54:08 UTC
+++ hwy/base.h
@@ -381,7 +381,7 @@ using float16_t = __fp16;
 //    which is missing __extendhfsf2.
 #elif (                                                                        \
     (HWY_ARCH_RVV && defined(__riscv_zvfh) && HWY_COMPILER_CLANG) ||           \
-    (HWY_ARCH_X86 && ((HWY_COMPILER_CLANG >= 1600 && !HWY_COMPILER_CLANGCL) || \
+    (HWY_ARCH_X86_64 && ((HWY_COMPILER_CLANG >= 1600 && !HWY_COMPILER_CLANGCL) || \
                       HWY_COMPILER_GCC_ACTUAL >= 1200)))
 using float16_t = _Float16;
 // 3) Otherwise emulate
