--- chrome/browser/metrics/power/process_monitor.cc.orig	2024-04-15 20:33:47 UTC
+++ chrome/browser/metrics/power/process_monitor.cc
@@ -61,7 +61,7 @@ ProcessMonitor::Metrics SampleMetrics(base::ProcessMet
   metrics.cpu_usage = process_metrics.GetPlatformIndependentCPUUsage();
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics.idle_wakeups = process_metrics.GetIdleWakeupsPerSecond();
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -79,7 +79,7 @@ void ScaleMetrics(ProcessMonitor::Metrics* metrics, do
   }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics->idle_wakeups *= factor;
 #endif
 
@@ -167,7 +167,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
   }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
