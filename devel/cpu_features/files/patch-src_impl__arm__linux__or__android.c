--- src/impl_arm_linux_or_android.c.orig	2025-09-21 09:55:17 UTC
+++ src/impl_arm_linux_or_android.c
@@ -15,7 +15,7 @@
 #include "cpu_features_macros.h"
 
 #ifdef CPU_FEATURES_ARCH_ARM
-#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID)
+#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID) || defined(CPU_FEATURES_OS_FREEBSD)
 
 #include "cpuinfo_arm.h"
 
@@ -195,7 +195,9 @@ ArmInfo GetArmInfo(void) {
   ArmInfo info = kEmptyArmInfo;
   ProcCpuInfoData proc_cpu_info_data = kEmptyProcCpuInfoData;
 
+#ifndef CPU_FEATURES_OS_FREEBSD
   FillProcCpuInfoData(&info, &proc_cpu_info_data);
+#endif
   const HardwareCapabilities hwcaps = CpuFeatures_GetHardwareCapabilities();
   for (size_t i = 0; i < ARM_LAST_; ++i) {
     if (CpuFeatures_IsHwCapsSet(kHardwareCapabilities[i], hwcaps)) {
