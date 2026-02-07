--- base/process/process_metrics.cc.orig	2025-03-24 20:50:14 UTC
+++ base/process/process_metrics.cc
@@ -17,7 +17,7 @@ namespace {
 namespace {
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 int CalculateEventsPerSecond(uint64_t event_count,
                              uint64_t* last_event_count,
                              base::TimeTicks* last_calculated) {
@@ -54,7 +54,7 @@ SystemMetrics SystemMetrics::Sample() {
   SystemMetrics system_metrics;
 
   system_metrics.committed_memory_ = GetSystemCommitCharge();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   GetSystemMemoryInfo(&system_metrics.memory_info_);
   GetVmStatInfo(&system_metrics.vmstat_info_);
   GetSystemDiskInfo(&system_metrics.disk_info_);
@@ -73,7 +73,7 @@ Value::Dict SystemMetrics::ToDict() const {
   Value::Dict res;
 
   res.Set("committed_memory", static_cast<int>(committed_memory_));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   Value::Dict meminfo = memory_info_.ToDict();
   meminfo.Merge(vmstat_info_.ToDict());
   res.Set("meminfo", std::move(meminfo));
@@ -100,7 +100,6 @@ std::unique_ptr<ProcessMetrics> ProcessMetrics::Create
 #endif  // !BUILDFLAG(IS_MAC)
 }
 
-#if !BUILDFLAG(IS_FREEBSD) || !BUILDFLAG(IS_POSIX)
 double ProcessMetrics::GetPlatformIndependentCPUUsage(
     TimeDelta cumulative_cpu) {
   TimeTicks time = TimeTicks::Now();
@@ -130,10 +129,9 @@ ProcessMetrics::GetPlatformIndependentCPUUsage() {
     return GetPlatformIndependentCPUUsage(cpu_usage);
   });
 }
-#endif
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 int ProcessMetrics::CalculateIdleWakeupsPerSecond(
     uint64_t absolute_idle_wakeups) {
   return CalculateEventsPerSecond(absolute_idle_wakeups,
