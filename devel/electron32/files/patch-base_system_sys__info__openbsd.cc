--- base/system/sys_info_openbsd.cc.orig	2024-06-18 21:43:18 UTC
+++ base/system/sys_info_openbsd.cc
@@ -3,7 +3,6 @@
 // found in the LICENSE file.
 
 #include "base/system/sys_info.h"
-
 #include <stddef.h>
 #include <stdint.h>
 #include <sys/param.h>
@@ -12,6 +11,7 @@
 
 #include "base/notreached.h"
 #include "base/posix/sysctl.h"
+#include "base/strings/string_util.h"
 
 namespace {
 
@@ -27,9 +27,14 @@ namespace base {
 
 namespace base {
 
+// pledge(2)
+uint64_t aofpmem = 0;
+uint64_t shmmax = 0;
+char cpumodel[256];
+
 // static
 int SysInfo::NumberOfProcessors() {
-  int mib[] = {CTL_HW, HW_NCPU};
+  int mib[] = {CTL_HW, HW_NCPUONLINE};
   int ncpu;
   size_t size = sizeof(ncpu);
   if (sysctl(mib, std::size(mib), &ncpu, &size, NULL, 0) < 0) {
@@ -41,10 +46,26 @@ uint64_t SysInfo::AmountOfPhysicalMemoryImpl() {
 
 // static
 uint64_t SysInfo::AmountOfPhysicalMemoryImpl() {
-  return AmountOfMemory(_SC_PHYS_PAGES);
+  // pledge(2)
+  if (!aofpmem)
+    aofpmem = AmountOfMemory(_SC_PHYS_PAGES);
+  return aofpmem;
 }
 
 // static
+std::string SysInfo::CPUModelName() {
+  int mib[] = {CTL_HW, HW_MODEL};
+  size_t len = std::size(cpumodel);
+
+  if (cpumodel[0] == '\0') {
+    if (sysctl(mib, std::size(mib), cpumodel, &len, NULL, 0) < 0)
+      return std::string();
+  }
+
+  return std::string(cpumodel, len - 1);
+}
+
+// static
 uint64_t SysInfo::AmountOfAvailablePhysicalMemoryImpl() {
   // We should add inactive file-backed memory also but there is no such
   // information from OpenBSD unfortunately.
@@ -56,16 +77,28 @@ uint64_t SysInfo::MaxSharedMemorySize() {
   int mib[] = {CTL_KERN, KERN_SHMINFO, KERN_SHMINFO_SHMMAX};
   size_t limit;
   size_t size = sizeof(limit);
+  // pledge(2)
+  if (shmmax)
+    goto out;
   if (sysctl(mib, std::size(mib), &limit, &size, NULL, 0) < 0) {
     NOTREACHED_IN_MIGRATION();
     return 0;
   }
-  return static_cast<uint64_t>(limit);
+  shmmax = static_cast<uint64_t>(limit);
+out:
+  return shmmax;
 }
 
 // static
-std::string SysInfo::CPUModelName() {
-  return StringSysctl({CTL_HW, HW_MODEL}).value();
+SysInfo::HardwareInfo SysInfo::GetHardwareInfoSync() {
+  HardwareInfo info;
+  // Set the manufacturer to "OpenBSD" and the model to
+  // an empty string.
+  info.manufacturer = "OpenBSD";
+  info.model = HardwareModelName();
+  DCHECK(IsStringUTF8(info.manufacturer));
+  DCHECK(IsStringUTF8(info.model));
+  return info;
 }
 
 }  // namespace base
