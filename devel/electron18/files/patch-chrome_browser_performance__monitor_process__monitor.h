--- chrome/browser/performance_monitor/process_monitor.h.orig	2022-05-19 05:17:37 UTC
+++ chrome/browser/performance_monitor/process_monitor.h
@@ -52,7 +52,7 @@ class ProcessMonitor {
     double cpu_usage = 0.0;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
     int idle_wakeups = 0;
