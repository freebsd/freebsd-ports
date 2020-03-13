--- third_party/zlib/arm_features.c.orig	2019-12-12 12:41:30 UTC
+++ third_party/zlib/arm_features.c
@@ -16,6 +16,10 @@ int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 #include <pthread.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <machine/armreg.h>
+#include <sys/types.h>
+#else
 #if defined(ARMV8_OS_ANDROID)
 #include <cpu-features.h>
 #elif defined(ARMV8_OS_LINUX)
@@ -30,6 +34,7 @@ int ZLIB_INTERNAL arm_cpu_enable_pmull = 0;
 #else
 #error arm_features.c ARM feature detection in not defined for your platform
 #endif
+#endif
 
 static void _arm_check_features(void);
 
@@ -68,14 +73,24 @@ static void _arm_check_features(void)
     arm_cpu_enable_crc32 = !!(features & ANDROID_CPU_ARM_FEATURE_CRC32);
     arm_cpu_enable_pmull = !!(features & ANDROID_CPU_ARM_FEATURE_PMULL);
 #elif defined(ARMV8_OS_LINUX) && defined(__aarch64__)
+#if defined(__FreeBSD__)
+    uint64_t id_aa64isar0 = READ_SPECIALREG(ID_AA64ISAR0_EL1);
+    if (ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL)
+        arm_cpu_enable_pmull = 1;
+    if (ID_AA64ISAR0_CRC32(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE)
+        arm_cpu_enable_crc32 = 1;
+#else
     unsigned long features = getauxval(AT_HWCAP);
     arm_cpu_enable_crc32 = !!(features & HWCAP_CRC32);
     arm_cpu_enable_pmull = !!(features & HWCAP_PMULL);
+#endif
 #elif defined(ARMV8_OS_LINUX) && (defined(__ARM_NEON) || defined(__ARM_NEON__))
+#if !defined(__FreeBSD__)
     /* Query HWCAP2 for ARMV8-A SoCs running in aarch32 mode */
     unsigned long features = getauxval(AT_HWCAP2);
     arm_cpu_enable_crc32 = !!(features & HWCAP2_CRC32);
     arm_cpu_enable_pmull = !!(features & HWCAP2_PMULL);
+#endif
 #elif defined(ARMV8_OS_FUCHSIA)
     uint32_t features;
     zx_status_t rc = zx_system_get_features(ZX_FEATURE_KIND_CPU, &features);
