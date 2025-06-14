--- libraries/botan/botan.cpp.orig	2025-06-01 19:29:53 UTC
+++ libraries/botan/botan.cpp
@@ -6138,7 +6138,7 @@ uint64_t CPUID::CPUID_Data::detect_cpu_features(size_t
 
     if (error == 0 && vector_type > 0) return CPUID::CPUID_ALTIVEC_BIT;
 
-#elif (defined(BOTAN_TARGET_OS_HAS_GETAUXVAL) || defined(BOTAN_TARGET_HAS_ELF_AUX_INFO)) && \
+#elif (defined(BOTAN_TARGET_OS_HAS_GETAUXVAL) || defined(BOTAN_TARGET_OS_HAS_ELF_AUX_INFO)) && \
     defined(BOTAN_TARGET_ARCH_IS_PPC64)
 
     enum PPC_hwcap_bit {
@@ -6223,8 +6223,7 @@ uint64_t CPUID::CPUID_Data::detect_cpu_features(size_t
 #include <intrin.h>
 #elif defined(BOTAN_BUILD_COMPILER_IS_INTEL)
 #include <ia32intrin.h>
-#elif defined(BOTAN_BUILD_COMPILER_IS_GCC) && (BOTAN_GCC_VERSION >= 430)
-     // Only available starting in GCC 4.3
+#elif defined(BOTAN_BUILD_COMPILER_IS_GCC) || defined(BOTAN_BUILD_COMPILER_IS_CLANG)
 #include <cpuid.h>
 
 namespace {
