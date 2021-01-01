--- base/process/process_metrics.h.orig	2019-12-12 12:38:59 UTC
+++ base/process/process_metrics.h
@@ -41,7 +41,7 @@ namespace base {
 // Full declaration is in process_metrics_iocounters.h.
 struct IoCounters;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // Minor and major page fault counts since the process creation.
 // Both counts are process-wide, and exclude child processes.
 //
@@ -51,7 +51,7 @@ struct PageFaultCounts {
   int64_t minor;
   int64_t major;
 };
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // Convert a POSIX timeval to microseconds.
 BASE_EXPORT int64_t TimeValToMicroseconds(const struct timeval& tv);
@@ -92,7 +92,7 @@ class BASE_EXPORT ProcessMetrics {
   // convenience wrapper for CreateProcessMetrics().
   static std::unique_ptr<ProcessMetrics> CreateCurrentProcessMetrics();
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Resident Set Size is a Linux/Android specific memory concept. Do not
   // attempt to extend this to other platforms.
   BASE_EXPORT size_t GetResidentSetSize() const;
@@ -172,14 +172,14 @@ class BASE_EXPORT ProcessMetrics {
   int GetOpenFdSoftLimit() const;
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
 
   // Minor and major page fault count as reported by /proc/[pid]/stat.
   // Returns true for success.
   bool GetPageFaultCounts(PageFaultCounts* counts) const;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
   // Returns total memory usage of malloc.
   size_t GetMallocUsage();
@@ -191,7 +191,7 @@ class BASE_EXPORT ProcessMetrics {
   ProcessMetrics(ProcessHandle process, PortProvider* port_provider);
 #endif  // !defined(OS_MACOSX) || defined(OS_IOS)
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   int CalculateIdleWakeupsPerSecond(uint64_t absolute_idle_wakeups);
 #endif
 #if defined(OS_MACOSX)
@@ -220,7 +220,7 @@ class BASE_EXPORT ProcessMetrics {
   // Number of bytes transferred to/from disk in bytes.
   uint64_t last_cumulative_disk_usage_ = 0;
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   // Same thing for idle wakeups.
   TimeTicks last_idle_wakeups_time_;
   uint64_t last_absolute_idle_wakeups_;
@@ -271,7 +271,7 @@ BASE_EXPORT size_t GetHandleLimit();
 BASE_EXPORT void IncreaseFdLimitTo(unsigned int max_descriptors);
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
@@ -305,7 +305,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int avail_phys = 0;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
   // This provides an estimate of available memory as described here:
   // https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=34e431b0ae398fc54ea69ff85ec700722c9da773
   // NOTE: this is ONLY valid in kernels 3.14 and up.  Its value will always
@@ -319,7 +319,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int swap_free = 0;
 #endif
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) || \
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   int buffers = 0;
   int cached = 0;
@@ -329,7 +329,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int inactive_file = 0;
   int dirty = 0;
   int reclaimable = 0;
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) ||
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD) ||
         // defined(OS_FUCHSIA)
 
 #if defined(OS_CHROMEOS)
@@ -355,10 +355,10 @@ struct BASE_EXPORT SystemMemoryInfoKB {
 // Exposed for memory debugging widget.
 BASE_EXPORT bool GetSystemMemoryInfo(SystemMemoryInfoKB* meminfo);
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         // defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
@@ -431,7 +431,7 @@ BASE_EXPORT bool GetSystemDiskInfo(SystemDiskInfo* dis
 // Returns the amount of time spent in user space since boot across all CPUs.
 BASE_EXPORT TimeDelta GetUserCpuTimeSinceBoot();
 
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
 // Data from files in directory /sys/block/zram0 about ZRAM usage.
@@ -526,7 +526,7 @@ class BASE_EXPORT SystemMetrics {
   FRIEND_TEST_ALL_PREFIXES(SystemMetricsTest, SystemMetrics);
 
   size_t committed_memory_;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   SystemMemoryInfoKB memory_info_;
   VmStatInfo vmstat_info_;
   SystemDiskInfo disk_info_;
