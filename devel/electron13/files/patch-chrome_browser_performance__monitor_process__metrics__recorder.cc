--- chrome/browser/performance_monitor/process_metrics_recorder.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/performance_monitor/process_metrics_recorder.cc
@@ -32,7 +32,7 @@ void RecordProcessHistograms(const char* histogram_suf
                        ""),
       metrics.cpu_usage * kCPUUsageFactor, kCPUUsageHistogramMin,
       kCPUUsageHistogramMax, kCPUUsageHistogramBucketCount);
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   base::UmaHistogramCounts10000(
       base::JoinString({"PerformanceMonitor.IdleWakeUps.", histogram_suffix},
