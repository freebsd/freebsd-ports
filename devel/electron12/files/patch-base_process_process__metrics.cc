--- base/process/process_metrics.cc.orig	2021-04-14 01:08:36 UTC
+++ base/process/process_metrics.cc
@@ -50,7 +50,7 @@ SystemMetrics SystemMetrics::Sample() {
   SystemMetrics system_metrics;
 
   system_metrics.committed_memory_ = GetSystemCommitCharge();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   GetSystemMemoryInfo(&system_metrics.memory_info_);
   GetVmStatInfo(&system_metrics.vmstat_info_);
   GetSystemDiskInfo(&system_metrics.disk_info_);
@@ -69,7 +69,7 @@ std::unique_ptr<Value> SystemMetrics::ToValue() const 
   std::unique_ptr<DictionaryValue> res(new DictionaryValue());
 
   res->SetIntKey("committed_memory", static_cast<int>(committed_memory_));
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   std::unique_ptr<DictionaryValue> meminfo = memory_info_.ToValue();
   std::unique_ptr<DictionaryValue> vmstat = vmstat_info_.ToValue();
   meminfo->MergeDictionary(vmstat.get());
@@ -120,7 +120,7 @@ double ProcessMetrics::GetPlatformIndependentCPUUsage(
 }
 #endif
 
-#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
 int ProcessMetrics::CalculateIdleWakeupsPerSecond(
     uint64_t absolute_idle_wakeups) {
@@ -133,7 +133,7 @@ int ProcessMetrics::GetIdleWakeupsPerSecond() {
   NOTIMPLEMENTED();  // http://crbug.com/120488
   return 0;
 }
-#endif  // defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
+#endif  // defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) ||
         // defined(OS_AIX)
 
 #if defined(OS_APPLE)
