https://reviews.llvm.org/D109330

--- src/llvm-project/compiler-rt/lib/builtins/cpu_model.c.orig	2021-07-12 08:53:30 UTC
+++ src/llvm-project/compiler-rt/lib/builtins/cpu_model.c
@@ -775,8 +775,14 @@ _Bool __aarch64_have_lse_atomics
 #define HWCAP_ATOMICS (1 << 8)
 #endif
 static void CONSTRUCTOR_ATTRIBUTE init_have_lse_atomics(void) {
+#if defined(__FreeBSD__)
+  unsigned long hwcap;
+  int result = elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+  __aarch64_have_lse_atomics = result == 0 && (hwcap & HWCAP_ATOMICS) != 0;
+#else
   unsigned long hwcap = getauxval(AT_HWCAP);
   __aarch64_have_lse_atomics = (hwcap & HWCAP_ATOMICS) != 0;
+#endif
 }
 #endif // defined(__has_include)
 #endif // __has_include(<sys/auxv.h>)
