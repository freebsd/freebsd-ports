--- src/openrct2/util/Util.cpp.orig	2018-03-18 20:26:14 UTC
+++ src/openrct2/util/Util.cpp
@@ -222,7 +222,7 @@ bool avx2_available()
 // https://github.com/gcc-mirror/gcc/commit/132fa33ce998df69a9f793d63785785f4b93e6f1
 // which causes it to ignore subleafs, but the new function is unavailable on Ubuntu's
 // prehistoric toolchains
-#if defined(OpenRCT2_CPUID_GNUC_X86)
+#if defined(OpenRCT2_CPUID_GNUC_X86) && (!defined(__FreeBSD__) || (__FreeBSD__ > 10))
     return __builtin_cpu_supports("avx2");
 #else
     // AVX2 support is declared as the 5th bit of EBX with CPUID(EAX = 7, ECX = 0).
