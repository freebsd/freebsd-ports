--- chrome/browser/performance_monitor/process_monitor.cc.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/performance_monitor/process_monitor.cc
@@ -64,7 +64,7 @@ ProcessMonitor::Metrics SampleMetrics(base::ProcessMet
   metrics.precise_cpu_usage = process_metrics.GetPreciseCPUUsage();
 #endif
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics.idle_wakeups = process_metrics.GetIdleWakeupsPerSecond();
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -119,7 +119,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
