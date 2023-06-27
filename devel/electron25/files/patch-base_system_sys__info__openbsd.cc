--- base/system/sys_info_openbsd.cc.orig	2022-08-31 12:19:35 UTC
+++ base/system/sys_info_openbsd.cc
@@ -11,6 +11,7 @@
 #include <sys/sysctl.h>
 
 #include "base/notreached.h"
+#include "base/strings/string_util.h"
 
 namespace {
 
@@ -26,9 +27,15 @@ uint64_t AmountOfMemory(int pages_name) {
 
 namespace base {
 
+// pledge(2)
+int64_t aofpmem = 0;
+int64_t aofapmem = 0;
+int64_t shmmax = 0;
+char cpumodel[256];
+
 // static
 int SysInfo::NumberOfProcessors() {
-  int mib[] = {CTL_HW, HW_NCPU};
+  int mib[] = {CTL_HW, HW_NCPUONLINE};
   int ncpu;
   size_t size = sizeof(ncpu);
   if (sysctl(mib, std::size(mib), &ncpu, &size, NULL, 0) < 0) {
@@ -40,10 +47,26 @@ int SysInfo::NumberOfProcessors() {
 
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
@@ -55,23 +78,28 @@ uint64_t SysInfo::MaxSharedMemorySize() {
   int mib[] = {CTL_KERN, KERN_SHMINFO, KERN_SHMINFO_SHMMAX};
   size_t limit;
   size_t size = sizeof(limit);
+  // pledge(2)
+  if (shmmax)
+    goto out;
   if (sysctl(mib, std::size(mib), &limit, &size, NULL, 0) < 0) {
     NOTREACHED();
     return 0;
   }
-  return static_cast<uint64_t>(limit);
+  shmmax = static_cast<uint64_t>(limit);
+out:
+  return shmmax;
 }
 
 // static
-std::string SysInfo::CPUModelName() {
-  int mib[] = {CTL_HW, HW_MODEL};
-  char name[256];
-  size_t len = std::size(name);
-  if (sysctl(mib, std::size(mib), name, &len, NULL, 0) < 0) {
-    NOTREACHED();
-    return std::string();
-  }
-  return name;
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
