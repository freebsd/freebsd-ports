-- Use elf_aux_info(3) and machine/elf.h for ARMv8 feature detection on FreeBSD.
-- <asm/hwcap.h> is Linux-only; the build treats FreeBSD as Linux (ARMV8_OS_LINUX),
-- so zlib fails to compile on aarch64.

--- third_party/zlib/cpu_features.c.orig	2026-09-24 10:00:00 UTC
+++ third_party/zlib/cpu_features.c
@@ -46,7 +46,11 @@
 #if defined(ARMV8_OS_ANDROID)
 #include <cpu-features.h>
 #elif defined(ARMV8_OS_LINUX)
+#if defined(__FreeBSD__)
+#include <machine/elf.h>
+#else
 #include <asm/hwcap.h>
+#endif
 #include <sys/auxv.h>
 #elif defined(ARMV8_OS_FUCHSIA)
 #include <zircon/features.h>
@@ -114,7 +118,12 @@
     arm_cpu_enable_crc32 = !!(features & ANDROID_CPU_ARM_FEATURE_CRC32);
     arm_cpu_enable_pmull = !!(features & ANDROID_CPU_ARM_FEATURE_PMULL);
 #elif defined(ARMV8_OS_LINUX) && defined(__aarch64__)
-    unsigned long features = getauxval(AT_HWCAP);
+    unsigned long features = 0;
+#if defined(__FreeBSD__)
+    elf_aux_info(AT_HWCAP, &features, sizeof(features));
+#else
+    features = getauxval(AT_HWCAP);
+#endif
     arm_cpu_enable_crc32 = !!(features & HWCAP_CRC32);
     arm_cpu_enable_pmull = !!(features & HWCAP_PMULL);
 #elif defined(ARMV8_OS_LINUX) && (defined(__ARM_NEON) || defined(__ARM_NEON__))
