--- base/process/process_metrics_freebsd.cc.orig	2022-09-25 13:48:17 UTC
+++ base/process/process_metrics_freebsd.cc
@@ -3,20 +3,39 @@
 // found in the LICENSE file.
 
 #include "base/process/process_metrics.h"
+#include "base/notreached.h"
 
 #include <stddef.h>
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <unistd.h>
 
+#include <fcntl.h> /* O_RDONLY */
+#include <kvm.h>
+#include <libutil.h>
+
 #include "base/memory/ptr_util.h"
 #include "base/process/process_metrics_iocounters.h"
+#include "base/values.h"
 
 namespace base {
+namespace {
+int GetPageShift() {
+  int pagesize = getpagesize();
+  int pageshift = 0;
 
+  while (pagesize > 1) {
+    pageshift++;
+    pagesize >>= 1;
+  }
+
+  return pageshift;
+}
+}
+
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
-    : process_(process),
-      last_cpu_(0) {}
+    : process_(process) {}
 
 // static
 std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
@@ -24,22 +43,19 @@ std::unique_ptr<ProcessMetrics> ProcessMetrics::Create
   return WrapUnique(new ProcessMetrics(process));
 }
 
-double ProcessMetrics::GetPlatformIndependentCPUUsage() {
+TimeDelta ProcessMetrics::GetCumulativeCPUUsage() {
   struct kinfo_proc info;
-  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, process_};
-  size_t length = sizeof(info);
+  size_t length = sizeof(struct kinfo_proc);
+  struct timeval tv;
 
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process_ };
+
   if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0)
-    return 0;
+    return TimeDelta();
 
-  return (info.ki_pctcpu / FSCALE) * 100.0;
+  return Microseconds(info.ki_runtime);
 }
 
-TimeDelta ProcessMetrics::GetCumulativeCPUUsage() {
-  NOTREACHED();
-  return TimeDelta();
-}
-
 bool ProcessMetrics::GetIOCounters(IoCounters* io_counters) const {
   return false;
 }
@@ -67,4 +83,221 @@ size_t GetSystemCommitCharge() {
   return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
 }
 
+int64_t GetNumberOfThreads(ProcessHandle process) {
+  // Taken from FreeBSD top (usr.bin/top/machine.c)
+
+  kvm_t* kd = kvm_open(NULL, "/dev/null", NULL, O_RDONLY, "kvm_open");
+  if (kd == NULL)
+    return 0;
+
+  struct kinfo_proc* pbase;
+  int nproc;
+  pbase = kvm_getprocs(kd, KERN_PROC_PID, process, &nproc);
+  if (pbase == NULL)
+    return 0;
+
+  if (kvm_close(kd) == -1)
+    return 0;
+
+  return nproc;
+}
+
+bool GetSystemMemoryInfo(SystemMemoryInfoKB *meminfo) {
+  unsigned int mem_total, mem_free, swap_total, swap_used;
+  size_t length;
+  int pagesizeKB;
+
+  pagesizeKB = getpagesize() / 1024;
+
+  length = sizeof(mem_total);
+  if (sysctlbyname("vm.stats.vm.v_page_count", &mem_total,
+      &length, NULL, 0) != 0 || length != sizeof(mem_total))
+    return false;
+
+  length = sizeof(mem_free);
+  if (sysctlbyname("vm.stats.vm.v_free_count", &mem_free, &length, NULL, 0)
+      != 0 || length != sizeof(mem_free))
+    return false;
+
+  length = sizeof(swap_total);
+  if (sysctlbyname("vm.swap_size", &swap_total, &length, NULL, 0)
+      != 0 || length != sizeof(swap_total))
+    return false;
+
+  length = sizeof(swap_used);
+  if (sysctlbyname("vm.swap_anon_use", &swap_used, &length, NULL, 0)
+      != 0 || length != sizeof(swap_used))
+    return false;
+
+  meminfo->total = mem_total * pagesizeKB;
+  meminfo->free = mem_free * pagesizeKB;
+  meminfo->swap_total = swap_total * pagesizeKB;
+  meminfo->swap_free = (swap_total - swap_used) * pagesizeKB;
+
+  return true;
+}
+
+int ProcessMetrics::GetOpenFdCount() const {
+  struct kinfo_file * kif;
+  int cnt;
+
+  if ((kif = kinfo_getfile(process_, &cnt)) == NULL)
+    return -1;
+
+  free(kif);
+
+  return cnt;
+}
+
+int ProcessMetrics::GetOpenFdSoftLimit() const {
+  size_t length;
+  int total_count = 0;
+  int mib[] = { CTL_KERN, KERN_MAXFILESPERPROC };
+
+  length = sizeof(total_count);
+
+  if (sysctl(mib, std::size(mib), &total_count, &length, NULL, 0) < 0) {
+    total_count = -1;
+  }
+
+  return total_count;
+}
+
+size_t ProcessMetrics::GetResidentSetSize() const {
+  kvm_t *kd = kvm_open(nullptr, "/dev/null", nullptr, O_RDONLY, "kvm_open");
+
+  if (kd == nullptr)
+    return 0;
+
+  struct kinfo_proc *pp;
+  int nproc;
+
+  if ((pp = kvm_getprocs(kd, KERN_PROC_PID, process_, &nproc)) == nullptr) {
+    kvm_close(kd);
+    return 0;
+  }
+  
+  size_t rss;
+
+  if (nproc > 0) {
+    rss = pp->ki_rssize << GetPageShift();
+  } else {
+    rss = 0;
+  }
+
+  kvm_close(kd);
+  return rss;
+}
+
+uint64_t ProcessMetrics::GetVmSwapBytes() const {
+  kvm_t *kd = kvm_open(nullptr, "/dev/null", nullptr, O_RDONLY, "kvm_open");
+
+  if (kd == nullptr)
+    return 0;
+
+  struct kinfo_proc *pp;
+  int nproc;
+
+  if ((pp = kvm_getprocs(kd, KERN_PROC_PID, process_, &nproc)) == nullptr) {
+    kvm_close(kd);
+    return 0;
+  }
+  
+  size_t swrss;
+
+  if (nproc > 0) {
+    swrss = pp->ki_swrss > pp->ki_rssize
+      ? (pp->ki_swrss - pp->ki_rssize) << GetPageShift()
+      : 0;
+  } else {
+    swrss = 0;
+  }
+
+  kvm_close(kd);
+  return swrss;
+}
+
+int ProcessMetrics::GetIdleWakeupsPerSecond() {
+  NOTIMPLEMENTED();
+  return 0;
+}
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
+  return res;
+}
+
+Value SystemMemoryInfoKB::ToValue() const {
+  Value res(Value::Type::DICTIONARY);
+
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
+  return res;
+}
+
+Value VmStatInfo::ToValue() const {
+  Value res(Value::Type::DICTIONARY);
+
+  res.SetIntKey("pswpin", pswpin);
+  res.SetIntKey("pswpout", pswpout);
+  res.SetIntKey("pgmajfault", pgmajfault);
+
+  return res;
+}
 }  // namespace base
