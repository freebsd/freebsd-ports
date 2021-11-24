--- chrome/browser/performance_monitor/process_metrics_history.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/performance_monitor/process_metrics_history.cc
@@ -39,7 +39,7 @@ ProcessMonitor::Metrics ProcessMetricsHistory::SampleM
   ProcessMonitor::Metrics metrics;
 
   metrics.cpu_usage = process_metrics_->GetPlatformIndependentCPUUsage();
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   metrics.idle_wakeups = process_metrics_->GetIdleWakeupsPerSecond();
 #endif
