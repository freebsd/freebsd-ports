--- src/arch/simddetect.cpp.orig	2022-04-02 13:06:33 UTC
+++ src/arch/simddetect.cpp
@@ -55,10 +55,12 @@
 #if defined(HAVE_NEON) && !defined(__aarch64__)
 #  ifdef ANDROID
 #    include <cpu-features.h>
-#  else
-/* Assume linux */
+#  elif defined(__linux__)
 #    include <asm/hwcap.h>
 #    include <sys/auxv.h>
+#  elif defined(__FreeBSD__)
+#    include <sys/auxv.h>
+#    include <sys/elf.h>
 #  endif
 #endif
 
@@ -85,7 +87,7 @@ SIMDDetect SIMDDetect::detector;
 bool SIMDDetect::neon_available_ = true;
 #elif defined(HAVE_NEON)
 // If true, then Neon has been detected.
-bool SIMDDetect::neon_available_;
+bool SIMDDetect::neon_available_ = false;
 #else
 // If true, then AVX has been detected.
 bool SIMDDetect::avx_available_;
@@ -216,9 +218,12 @@ SIMDDetect::SIMDDetect() {
     if (family == ANDROID_CPU_FAMILY_ARM)
       neon_available_ = (android_getCpuFeatures() & ANDROID_CPU_ARM_FEATURE_NEON);
   }
-#  else
-  /* Assume linux */
+#  elif defined(__linux__)
   neon_available_ = getauxval(AT_HWCAP) & HWCAP_NEON;
+#  elif defined(__FreeBSD__)
+  unsigned long hwcap = 0;
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+  neon_available_ = hwcap & HWCAP_NEON;
 #  endif
 #endif
 
