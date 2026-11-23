--- contrib/llvm-project/libunwind/src/Registers.hpp.orig	2026-11-10 10:33:04 UTC
+++ contrib/llvm-project/libunwind/src/Registers.hpp
@@ -1944,7 +1944,12 @@ class _LIBUNWIND_HIDDEN Registers_arm64 { (private)
   static bool checkHasSME() {
 #if defined(HAVE_SYS_AUXV_H)
     constexpr int hwcap2_sme = (1 << 23);
+#ifdef __FreeBSD__
+    unsigned long hwcap2;
+    elf_aux_info(AT_HWCAP2, &hwcap2, sizeof(hwcap2));
+#else
     unsigned long hwcap2 = getauxval(AT_HWCAP2);
+#endif
     return (hwcap2 & hwcap2_sme) != 0;
 #endif
     // TODO: Support other platforms.
