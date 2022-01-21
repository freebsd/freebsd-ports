--- third_party/abseil-cpp/absl/debugging/internal/vdso_support.cc.orig	2022-01-21 00:04:09 UTC
+++ third_party/abseil-cpp/absl/debugging/internal/vdso_support.cc
@@ -51,7 +51,9 @@
 #endif
 
 #if defined(__FreeBSD__)
+#if __ELF_WORD_SIZE == 64
 using Elf64_auxv_t = Elf64_Auxinfo;
+#endif
 using Elf32_auxv_t = Elf32_Auxinfo;
 #endif
 
