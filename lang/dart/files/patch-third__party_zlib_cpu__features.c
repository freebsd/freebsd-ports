Detect ARMv8 CRC32 and PMULL with elf_aux_info(AT_HWCAP) on
FreeBSD/aarch64 instead of the Linux-only <asm/hwcap.h> (series 1002).
For Chromium's zlib; not submitted upstream yet.
--- third_party/zlib/cpu_features.c.orig	2026-09-29 08:00:52 UTC
+++ third_party/zlib/cpu_features.c
@@ -39,7 +39,8 @@ int ZLIB_INTERNAL riscv_cpu_enable_vclmul = 0;
 #ifndef CPU_NO_SIMD
 
 #if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || \
-    defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_IOS)
+    defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_IOS) || \
+    defined(ARMV8_OS_FREEBSD)
 #include <pthread.h>
 #endif
 
@@ -48,6 +49,9 @@ int ZLIB_INTERNAL riscv_cpu_enable_vclmul = 0;
 #elif defined(ARMV8_OS_LINUX)
 #include <asm/hwcap.h>
 #include <sys/auxv.h>
+#elif defined(ARMV8_OS_FREEBSD)
+#include <sys/auxv.h>
+#include <machine/elf.h>
 #elif defined(ARMV8_OS_FUCHSIA)
 #include <zircon/features.h>
 #include <zircon/syscalls.h>
@@ -69,7 +73,7 @@ static void _cpu_check_features(void);
 #if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || \
     defined(ARMV8_OS_MACOS) || defined(ARMV8_OS_FUCHSIA) || \
     defined(X86_NOT_WINDOWS) || defined(ARMV8_OS_IOS) || \
-    defined(RISCV_RVV)
+    defined(RISCV_RVV) || defined(ARMV8_OS_FREEBSD)
 #if !defined(ARMV8_OS_MACOS)
 // _cpu_check_features() doesn't need to do anything on mac/arm since all
 // features are known at build time, so don't call it.
@@ -113,6 +117,12 @@ static void _cpu_check_features(void)
     uint64_t features = android_getCpuFeatures();
     arm_cpu_enable_crc32 = !!(features & ANDROID_CPU_ARM_FEATURE_CRC32);
     arm_cpu_enable_pmull = !!(features & ANDROID_CPU_ARM_FEATURE_PMULL);
+#elif defined(ARMV8_OS_FREEBSD) && defined(__aarch64__)
+    unsigned long features = 0;
+    if (elf_aux_info(AT_HWCAP, &features, sizeof(features)) != 0)
+        return;
+    arm_cpu_enable_crc32 = !!(features & HWCAP_CRC32);
+    arm_cpu_enable_pmull = !!(features & HWCAP_PMULL);
 #elif defined(ARMV8_OS_LINUX) && defined(__aarch64__)
     unsigned long features = getauxval(AT_HWCAP);
     arm_cpu_enable_crc32 = !!(features & HWCAP_CRC32);
