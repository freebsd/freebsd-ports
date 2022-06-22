--- base/process/process_metrics_openbsd.cc.orig	2022-05-19 05:17:34 UTC
+++ base/process/process_metrics_openbsd.cc
@@ -4,17 +4,36 @@
 
 #include "base/process/process_metrics.h"
 
+#include "base/files/file_util.h"
+#include "base/logging.h"
+#include "base/process/internal_linux.h"
+#include "base/strings/string_number_conversions.h"
+#include "base/strings/string_split.h"
+#include "base/strings/string_tokenizer.h"
+#include "base/strings/string_util.h"
+#include "base/system/sys_info.h"
+#include "base/threading/thread_restrictions.h"
+#include "base/notreached.h"
+
 #include <stddef.h>
 #include <stdint.h>
+#include <fcntl.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/vmmeter.h>
 
+#include <kvm.h>
+
 #include "base/cxx17_backports.h"
 #include "base/memory/ptr_util.h"
 #include "base/process/process_metrics_iocounters.h"
+#include "base/values.h"
 
 namespace base {
 
+ProcessMetrics::ProcessMetrics(ProcessHandle process)
+    : process_(process) {}
+
 // static
 std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
     ProcessHandle process) {
@@ -25,49 +44,24 @@ bool ProcessMetrics::GetIOCounters(IoCounters* io_coun
   return false;
 }
 
-static int GetProcessCPU(pid_t pid) {
+double ProcessMetrics::GetPlatformIndependentCPUUsage() {
   struct kinfo_proc info;
-  size_t length;
-  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, pid,
-                sizeof(struct kinfo_proc), 0 };
+  size_t length = sizeof(struct kinfo_proc);
 
-  if (sysctl(mib, base::size(mib), NULL, &length, NULL, 0) < 0)
-    return -1;
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process_,
+                sizeof(struct kinfo_proc), 1 };
 
-  mib[5] = (length / sizeof(struct kinfo_proc));
+  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0)
+    return 0.0;
 
-  if (sysctl(mib, base::size(mib), &info, &length, NULL, 0) < 0)
-    return 0;
-
-  return info.p_pctcpu;
+  return static_cast<double>((info.p_pctcpu * 100.0) / FSCALE);
 }
 
-double ProcessMetrics::GetPlatformIndependentCPUUsage() {
-  TimeTicks time = TimeTicks::Now();
-
-  if (last_cpu_time_.is_zero()) {
-    // First call, just set the last values.
-    last_cpu_time_ = time;
-    return 0;
-  }
-
-  int cpu = GetProcessCPU(process_);
-
-  last_cpu_time_ = time;
-  double percentage = static_cast<double>((cpu * 100.0) / FSCALE);
-
-  return percentage;
-}
-
 TimeDelta ProcessMetrics::GetCumulativeCPUUsage() {
   NOTREACHED();
   return TimeDelta();
 }
 
-ProcessMetrics::ProcessMetrics(ProcessHandle process)
-    : process_(process),
-      last_cpu_(0) {}
-
 size_t GetSystemCommitCharge() {
   int mib[] = { CTL_VM, VM_METER };
   int pagesize;
@@ -75,7 +69,7 @@ size_t GetSystemCommitCharge() {
   unsigned long mem_total, mem_free, mem_inactive;
   size_t len = sizeof(vmtotal);
 
-  if (sysctl(mib, base::size(mib), &vmtotal, &len, NULL, 0) < 0)
+  if (sysctl(mib, std::size(mib), &vmtotal, &len, NULL, 0) < 0)
     return 0;
 
   mem_total = vmtotal.t_vm;
@@ -85,6 +79,129 @@ size_t GetSystemCommitCharge() {
   pagesize = getpagesize();
 
   return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
+}
+
+int ProcessMetrics::GetOpenFdCount() const {
+  struct kinfo_file *files;
+  kvm_t *kd = NULL;
+  int total_count = 0;
+  char errbuf[_POSIX2_LINE_MAX];
+
+  if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, errbuf)) == NULL)
+    goto out;
+  
+  if ((files = kvm_getfiles(kd, KERN_FILE_BYPID, process_,  
+        sizeof(struct kinfo_file), &total_count)) == NULL) {
+	  total_count = 0;
+	  goto out;
+  }
+
+  kvm_close(kd);
+
+out:
+  return total_count;
+}
+
+int ProcessMetrics::GetOpenFdSoftLimit() const {
+  return GetMaxFds();
+}
+
+uint64_t ProcessMetrics::GetVmSwapBytes() const {
+  NOTIMPLEMENTED();
+  return 0;
+}
+
+bool GetSystemMemoryInfo(SystemMemoryInfoKB* meminfo) {
+  NOTIMPLEMENTED_LOG_ONCE();
+  return false;
+}
+
+SystemDiskInfo::SystemDiskInfo() {
+  reads = 0;
+  reads_merged = 0;
+  sectors_read = 0;
+  read_time = 0;
+  writes = 0;
+  writes_merged = 0;
+  sectors_written = 0;
+  write_time = 0;
+  io = 0;
+  io_time = 0;
+  weighted_io_time = 0;
+}
+     
+SystemDiskInfo::SystemDiskInfo(const SystemDiskInfo& other) = default;
+      
+bool GetSystemDiskInfo(SystemDiskInfo* diskinfo) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+bool GetVmStatInfo(VmStatInfo* vmstat) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+int ProcessMetrics::GetIdleWakeupsPerSecond() {
+  NOTIMPLEMENTED();
+  return 0;
+}
+
+Value SystemMemoryInfoKB::ToValue() const {
+  Value res(Value::Type::DICTIONARY);
+  res.SetIntKey("total", total);
+  res.SetIntKey("free", free);
+  res.SetIntKey("available", available);
+  res.SetIntKey("buffers", buffers);
+  res.SetIntKey("cached", cached);
+  res.SetIntKey("active_anon", active_anon);
+  res.SetIntKey("inactive_anon", inactive_anon);
+  res.SetIntKey("active_file", active_file);
+  res.SetIntKey("inactive_file", inactive_file);
+  res.SetIntKey("swap_total", swap_total);
+  res.SetIntKey("swap_free", swap_free);
+  res.SetIntKey("swap_used", swap_total - swap_free);
+  res.SetIntKey("dirty", dirty);
+  res.SetIntKey("reclaimable", reclaimable);
+
+  NOTIMPLEMENTED();
+
+  return res;
+}
+
+Value VmStatInfo::ToValue() const {   
+  Value res(Value::Type::DICTIONARY);
+  res.SetIntKey("pswpin", pswpin);
+  res.SetIntKey("pswpout", pswpout);
+  res.SetIntKey("pgmajfault", pgmajfault);
+
+  NOTIMPLEMENTED();
+
+  return res;
+}
+
+SystemDiskInfo& SystemDiskInfo::operator=(const SystemDiskInfo&) = default;
+
+Value SystemDiskInfo::ToValue() const {
+  Value res(Value::Type::DICTIONARY);
+
+  // Write out uint64_t variables as doubles.
+  // Note: this may discard some precision, but for JS there's no other option.
+  res.SetDoubleKey("reads", static_cast<double>(reads));
+  res.SetDoubleKey("reads_merged", static_cast<double>(reads_merged));
+  res.SetDoubleKey("sectors_read", static_cast<double>(sectors_read));
+  res.SetDoubleKey("read_time", static_cast<double>(read_time));
+  res.SetDoubleKey("writes", static_cast<double>(writes));
+  res.SetDoubleKey("writes_merged", static_cast<double>(writes_merged));
+  res.SetDoubleKey("sectors_written", static_cast<double>(sectors_written));
+  res.SetDoubleKey("write_time", static_cast<double>(write_time));
+  res.SetDoubleKey("io", static_cast<double>(io));
+  res.SetDoubleKey("io_time", static_cast<double>(io_time));
+  res.SetDoubleKey("weighted_io_time", static_cast<double>(weighted_io_time));
+
+  NOTIMPLEMENTED();
+
+  return res;
 }
 
 }  // namespace base
