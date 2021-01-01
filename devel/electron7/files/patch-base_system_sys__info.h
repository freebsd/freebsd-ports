--- base/system/sys_info.h.orig	2019-12-12 12:38:59 UTC
+++ base/system/sys_info.h
@@ -192,7 +192,7 @@ class BASE_EXPORT SysInfo {
   static bool IsLowEndDeviceImpl();
   static HardwareInfo GetHardwareInfoSync();
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
   static int64_t AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfoKB& meminfo);
 #endif
