--- src/impl_aarch64_linux_or_android.c.orig	2025-09-21 09:37:44 UTC
+++ src/impl_aarch64_linux_or_android.c
@@ -15,7 +15,7 @@
 #include "cpu_features_macros.h"
 
 #ifdef CPU_FEATURES_ARCH_AARCH64
-#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID)
+#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID) || defined(CPU_FEATURES_OS_FREEBSD)
 
 #include "impl_aarch64__base_implementation.inl"
 
@@ -43,7 +43,11 @@ static void FillProcCpuInfoData(Aarch64Info* const inf
 }
 
 static void FillProcCpuInfoData(Aarch64Info* const info) {
+#ifdef CPU_FEATURES_OS_FREEBSD
+  const int fd = CpuFeatures_OpenFile("/compat/linux/proc/cpuinfo");
+#else
   const int fd = CpuFeatures_OpenFile("/proc/cpuinfo");
+#endif
   if (fd >= 0) {
     StackLineReader reader;
     StackLineReader_Initialize(&reader, fd);
