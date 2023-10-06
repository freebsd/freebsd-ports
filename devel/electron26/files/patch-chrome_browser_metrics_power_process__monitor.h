--- chrome/browser/metrics/power/process_monitor.h.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/metrics/power/process_monitor.h
@@ -75,7 +75,7 @@ class ProcessMonitor : public content::BrowserChildPro
     double cpu_usage = 0.0;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
     int idle_wakeups = 0;
