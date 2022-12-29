--- base/system/sys_info_freebsd.cc.orig	2022-09-01 17:22:07 UTC
+++ base/system/sys_info_freebsd.cc
@@ -9,30 +9,106 @@
 #include <sys/sysctl.h>
 
 #include "base/notreached.h"
+#include "base/process/process_metrics.h"
+#include "base/strings/string_util.h"
 
 namespace base {
 
-int64_t SysInfo::AmountOfPhysicalMemoryImpl() {
-  int pages, page_size;
+int SysInfo::NumberOfProcessors() {
+  int mib[] = {CTL_HW, HW_NCPU};
+  int ncpu;
+  size_t size = sizeof(ncpu);
+  if (sysctl(mib, std::size(mib), &ncpu, &size, NULL, 0) < 0) {
+    NOTREACHED();
+    return 1;
+  }
+  return ncpu;
+}
+
+uint64_t SysInfo::AmountOfPhysicalMemoryImpl() {
+  int pages, page_size, r = 0;
   size_t size = sizeof(pages);
-  sysctlbyname("vm.stats.vm.v_page_count", &pages, &size, NULL, 0);
-  sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
-  if (pages == -1 || page_size == -1) {
+
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_page_count", &pages, &size, NULL, 0);
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
+
+  if (r == -1) {
     NOTREACHED();
     return 0;
   }
-  return static_cast<int64_t>(pages) * page_size;
+
+  return static_cast<uint64_t>(pages) * page_size;
 }
 
+uint64_t SysInfo::AmountOfAvailablePhysicalMemoryImpl() {
+  int page_size, r = 0;
+  unsigned int pgfree, pginact, pgcache;
+  size_t size = sizeof(page_size);
+  size_t szpg = sizeof(pgfree);
+
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_free_count", &pgfree, &szpg, NULL, 0);
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_inactive_count", &pginact, &szpg, NULL, 0);
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_cache_count", &pgcache, &szpg, NULL, 0);
+
+  if (r == -1) {
+    NOTREACHED();
+    return 0;
+  }
+
+  return static_cast<uint64_t>((pgfree + pginact + pgcache) * page_size);
+}
+
 // static
+uint64_t SysInfo::AmountOfAvailablePhysicalMemory(const SystemMemoryInfoKB& info) {
+  uint64_t res_kb = info.available != 0
+                       ? info.available - info.active_file
+                       : info.free + info.reclaimable + info.inactive_file;
+  return res_kb * 1024;
+}
+
+// static
+std::string SysInfo::CPUModelName() {
+  int mib[] = { CTL_HW, HW_MODEL };
+  char name[256];
+  size_t size = std::size(name);
+
+  if (sysctl(mib, std::size(mib), &name, &size, NULL, 0) == 0) {
+    return name;
+  }
+
+  return std::string();
+}
+
+// static
 uint64_t SysInfo::MaxSharedMemorySize() {
   size_t limit;
   size_t size = sizeof(limit);
+
   if (sysctlbyname("kern.ipc.shmmax", &limit, &size, NULL, 0) < 0) {
     NOTREACHED();
     return 0;
   }
+
   return static_cast<uint64_t>(limit);
+}
+
+SysInfo::HardwareInfo SysInfo::GetHardwareInfoSync() {
+  HardwareInfo info;
+
+  info.manufacturer = "FreeBSD";
+  info.model = HardwareModelName();
+
+  DCHECK(IsStringUTF8(info.manufacturer));
+  DCHECK(IsStringUTF8(info.model));
+
+  return info;
 }
 
 }  // namespace base
