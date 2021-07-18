--- chrome/browser/performance_monitor/process_metrics_history.cc.orig	2021-01-07 00:36:23 UTC
+++ chrome/browser/performance_monitor/process_metrics_history.cc
@@ -47,7 +47,7 @@ void ProcessMetricsHistory::SampleMetrics() {
 #if defined(OS_WIN)
   disk_usage_ = process_metrics_->GetDiskUsageBytesPerSecond();
 #endif
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   idle_wakeups_ = process_metrics_->GetIdleWakeupsPerSecond();
 #endif
@@ -91,7 +91,7 @@ void ProcessMetricsHistory::UpdateHistograms() {
           kDiskUsageHistogramMin, kDiskUsageHistogramMax,
           kDiskUsageHistogramBucketCount);
 #endif
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
       UMA_HISTOGRAM_COUNTS_10000(
           "PerformanceMonitor.IdleWakeups.BrowserProcess", idle_wakeups_);
@@ -113,7 +113,7 @@ void ProcessMetricsHistory::UpdateHistograms() {
         UMA_HISTOGRAM_BOOLEAN("PerformanceMonitor.HighCPU.RendererProcess",
                               true);
       }
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
       UMA_HISTOGRAM_COUNTS_10000(
           "PerformanceMonitor.IdleWakeups.RendererProcess", idle_wakeups_);
@@ -134,7 +134,7 @@ void ProcessMetricsHistory::UpdateHistograms() {
                                   kHistogramBucketCount);
       if (cpu_usage_ > kHighCPUUtilizationThreshold)
         UMA_HISTOGRAM_BOOLEAN("PerformanceMonitor.HighCPU.GPUProcess", true);
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
       UMA_HISTOGRAM_COUNTS_10000("PerformanceMonitor.IdleWakeups.GPUProcess",
                                  idle_wakeups_);
