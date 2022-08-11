--- chrome/browser/performance_monitor/process_metrics_recorder_util.cc.orig	2022-05-11 07:16:48 UTC
+++ chrome/browser/performance_monitor/process_metrics_recorder_util.cc
@@ -42,7 +42,7 @@ void RecordProcessHistograms(const char* histogram_suf
       metrics.cpu_usage * kCPUUsageFactor, kCPUUsageHistogramMin,
       kCPUUsageHistogramMax, kCPUUsageHistogramBucketCount);
 #if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
   base::UmaHistogramCounts10000(
       base::JoinString({"PerformanceMonitor.IdleWakeups.", histogram_suffix},
                        ""),
