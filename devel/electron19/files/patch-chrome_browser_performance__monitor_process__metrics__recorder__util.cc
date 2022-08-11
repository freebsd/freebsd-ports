--- chrome/browser/performance_monitor/process_metrics_recorder_util.cc.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/performance_monitor/process_metrics_recorder_util.cc
@@ -43,7 +43,7 @@ void RecordProcessHistograms(const char* histogram_suf
       kCPUUsageHistogramMax, kCPUUsageHistogramBucketCount);
 #endif
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   base::UmaHistogramCounts10000(
       base::StrCat({"PerformanceMonitor.IdleWakeups.", histogram_suffix}),
       metrics.idle_wakeups);
