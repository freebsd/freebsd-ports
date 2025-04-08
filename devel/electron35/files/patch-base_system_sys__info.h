--- base/system/sys_info.h.orig	2025-03-24 20:50:14 UTC
+++ base/system/sys_info.h
@@ -332,6 +332,8 @@ class BASE_EXPORT SysInfo {
   static void ResetCpuSecurityMitigationsEnabledForTesting();
 #endif
 
+  static uint64_t MaxSharedMemorySize();
+
  private:
   friend class test::ScopedAmountOfPhysicalMemoryOverride;
   FRIEND_TEST_ALL_PREFIXES(SysInfoTest, AmountOfAvailablePhysicalMemory);
@@ -344,7 +346,7 @@ class BASE_EXPORT SysInfo {
   static HardwareInfo GetHardwareInfoSync();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   static uint64_t AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfoKB& meminfo);
 #endif
