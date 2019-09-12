--- projects/openmp/runtime/src/kmp_platform.h.orig	2019-01-19 10:56:40 UTC
+++ projects/openmp/runtime/src/kmp_platform.h
@@ -93,9 +93,9 @@
 #define KMP_ARCH_X86 0
 #define KMP_ARCH_X86_64 0
 #define KMP_ARCH_AARCH64 0
-#define KMP_ARCH_PPC64_BE 0
-#define KMP_ARCH_PPC64_LE 0
-#define KMP_ARCH_PPC64 (KMP_ARCH_PPC64_LE || KMP_ARCH_PPC64_BE)
+#define KMP_ARCH_PPC64_ELFv1 0
+#define KMP_ARCH_PPC64_ELFv2 0
+#define KMP_ARCH_PPC64 (KMP_ARCH_PPC64_ELFv2 || KMP_ARCH_PPC64_ELFv1)
 #define KMP_ARCH_MIPS 0
 #define KMP_ARCH_MIPS64 0
 
@@ -117,12 +117,12 @@
 #undef KMP_ARCH_X86
 #define KMP_ARCH_X86 1
 #elif defined __powerpc64__
-#if defined __LITTLE_ENDIAN__
-#undef KMP_ARCH_PPC64_LE
-#define KMP_ARCH_PPC64_LE 1
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+#undef KMP_ARCH_PPC64_ELFv2
+#define KMP_ARCH_PPC64_ELFv2 1
 #else
-#undef KMP_ARCH_PPC64_BE
-#define KMP_ARCH_PPC64_BE 1
+#undef KMP_ARCH_PPC64_ELFv1
+#define KMP_ARCH_PPC64_ELFv1 1
 #endif
 #elif defined __aarch64__
 #undef KMP_ARCH_AARCH64
