--- base/cpu.cc.orig	2021-04-14 01:08:36 UTC
+++ base/cpu.cc
@@ -16,7 +16,7 @@
 
 #include "base/stl_util.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
 #include "base/containers/flat_set.h"
 #include "base/files/file_util.h"
@@ -212,6 +212,14 @@ const ProcCpuInfo& ParseProcCpu() {
 
   return *info;
 }
+#elif defined(OS_BSD)
+std::string* CpuInfoBrand() {
+  static std::string* brand = []() {
+    return new std::string(SysInfo::CPUModelName());
+  }();
+
+  return brand;
+}
 #endif  // defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) ||
         // defined(OS_LINUX) || defined(OS_CHROMEOS))
 
@@ -348,6 +356,8 @@ void CPU::Initialize() {
   has_bti_ = hwcap2 & HWCAP2_BTI;
 #endif
 
+#elif defined(OS_BSD)
+  cpu_brand_ = *CpuInfoBrand();
 #elif defined(OS_WIN)
   // Windows makes high-resolution thread timing information available in
   // user-space.
