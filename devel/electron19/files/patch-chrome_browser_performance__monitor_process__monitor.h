--- chrome/browser/performance_monitor/process_monitor.h.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/performance_monitor/process_monitor.h
@@ -78,7 +78,7 @@ class ProcessMonitor : public content::BrowserChildPro
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
     int idle_wakeups = 0;
