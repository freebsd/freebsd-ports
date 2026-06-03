--- components/sync/service/device_statistics_tracker.cc.orig	2026-04-28 21:06:17 UTC
+++ components/sync/service/device_statistics_tracker.cc
@@ -83,7 +83,7 @@ std::optional<DeviceStatisticsTracker::Platform> GetLo
   return DeviceStatisticsTracker::Platform::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return DeviceStatisticsTracker::Platform::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceStatisticsTracker::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
   return DeviceStatisticsTracker::Platform::kChromeOS;
