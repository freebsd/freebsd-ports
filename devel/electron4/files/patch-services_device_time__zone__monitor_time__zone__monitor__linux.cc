--- services/device/time_zone_monitor/time_zone_monitor_linux.cc.orig	2019-03-15 06:37:32 UTC
+++ services/device/time_zone_monitor/time_zone_monitor_linux.cc
@@ -89,7 +89,11 @@ class TimeZoneMonitorLinuxImpl
     // false positives are harmless, assuming the false positive rate is
     // reasonable.
     const char* const kFilesToWatch[] = {
+#if defined(OS_BSD)
+        "/etc/localtime",
+#else
         "/etc/localtime", "/etc/timezone", "/etc/TZ",
+#endif
     };
 
     for (size_t index = 0; index < arraysize(kFilesToWatch); ++index) {
