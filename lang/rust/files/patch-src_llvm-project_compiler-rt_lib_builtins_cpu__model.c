--- src/llvm-project/compiler-rt/lib/builtins/cpu_model.c.orig	2021-05-22 10:27:43 UTC
+++ src/llvm-project/compiler-rt/lib/builtins/cpu_model.c
@@ -775,7 +775,12 @@ _Bool __aarch64_have_lse_atomics
 #define HWCAP_ATOMICS (1 << 8)
 #endif
 static void CONSTRUCTOR_ATTRIBUTE init_have_lse_atomics(void) {
-  unsigned long hwcap = getauxval(AT_HWCAP);
+  unsigned long hwcap = 0;
+#if defined(__linux__)
+  hwcap = getauxval(AT_HWCAP);
+#elif defined(__FreeBSD__)
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof(unsigned long));
+#endif
   __aarch64_have_lse_atomics = (hwcap & HWCAP_ATOMICS) != 0;
 }
 #endif // defined(__has_include)
