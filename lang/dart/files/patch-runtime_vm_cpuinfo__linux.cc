Read the CPU model from sysctl hw.model instead of /proc/cpuinfo on
FreeBSD/aarch64 (series 0015). It is only displayed.
FreeBSD-specific, not submitted upstream yet.
--- runtime/vm/cpuinfo_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/vm/cpuinfo_linux.cc
@@ -5,6 +5,11 @@
 #include "vm/globals.h"
 #if defined(DART_HOST_OS_LINUX)
 
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>  // NOLINT
+#include <sys/types.h>   // NOLINT
+#endif
+
 #include "vm/cpuid.h"
 #include "vm/cpuinfo.h"
 #include "vm/proccpuinfo.h"
@@ -17,6 +22,25 @@ namespace dart {
 
 namespace dart {
 
+#if defined(__FreeBSD__)
+// FreeBSD has no /proc/cpuinfo, so kCpuInfoSystem reads sysctls instead, as
+// on macOS. Returns nullptr if the sysctl does not exist. Caller is
+// responsible for freeing the result.
+static char* ReadSysctlString(const char* name) {
+  size_t length = 0;
+  if (name == nullptr ||
+      sysctlbyname(name, nullptr, &length, nullptr, 0) != 0) {
+    return nullptr;
+  }
+  char* result = reinterpret_cast<char*>(malloc(length));
+  if (sysctlbyname(name, result, &length, nullptr, 0) != 0) {
+    free(result);
+    return nullptr;
+  }
+  return result;
+}
+#endif
+
 CpuInfoMethod CpuInfo::method_ = kCpuInfoDefault;
 const char* CpuInfo::fields_[kCpuInfoMax] = {};
 
@@ -37,6 +61,13 @@ void CpuInfo::Init() {
   fields_[kCpuInfoArchitecture] = "CPU architecture";
   method_ = kCpuInfoSystem;
   ProcCpuInfo::Init();
+#elif defined(HOST_ARCH_ARM64) && defined(__FreeBSD__)
+  fields_[kCpuInfoProcessor] = "hw.model";
+  fields_[kCpuInfoModel] = "hw.model";
+  fields_[kCpuInfoHardware] = "hw.model";
+  fields_[kCpuInfoFeatures] = nullptr;
+  fields_[kCpuInfoArchitecture] = nullptr;
+  method_ = kCpuInfoSystem;
 #elif defined(HOST_ARCH_ARM64)
   fields_[kCpuInfoProcessor] = "Processor";
   fields_[kCpuInfoModel] = "CPU implementer";
@@ -58,7 +89,9 @@ void CpuInfo::Cleanup() {
   if (method_ == kCpuInfoCpuId) {
     CpuId::Cleanup();
   } else if (method_ == kCpuInfoSystem) {
+#if !defined(__FreeBSD__)
     ProcCpuInfo::Cleanup();
+#endif
   } else {
     ASSERT(method_ == kCpuInfoNone);
   }
@@ -72,7 +105,15 @@ bool CpuInfo::FieldContains(CpuInfoIndices idx, const 
     free(const_cast<char*>(field));
     return contains;
   } else if (method_ == kCpuInfoSystem) {
+#if defined(__FreeBSD__)
+    char* field = ReadSysctlString(FieldName(idx));
+    if (field == nullptr) return false;
+    bool contains = (strstr(field, search_string) != nullptr);
+    free(field);
+    return contains;
+#else
     return ProcCpuInfo::FieldContains(FieldName(idx), search_string);
+#endif
   } else {
     UNREACHABLE();
   }
@@ -82,7 +123,11 @@ const char* CpuInfo::ExtractField(CpuInfoIndices idx) 
   if (method_ == kCpuInfoCpuId) {
     return CpuId::field(idx);
   } else if (method_ == kCpuInfoSystem) {
+#if defined(__FreeBSD__)
+    return ReadSysctlString(FieldName(idx));
+#else
     return ProcCpuInfo::ExtractField(FieldName(idx));
+#endif
   } else {
     UNREACHABLE();
   }
@@ -95,7 +140,12 @@ bool CpuInfo::HasField(const char* field) {
            (strcmp(field, fields_[kCpuInfoHardware]) == 0) ||
            (strcmp(field, fields_[kCpuInfoFeatures]) == 0);
   } else if (method_ == kCpuInfoSystem) {
+#if defined(__FreeBSD__)
+    return field != nullptr &&
+           sysctlbyname(field, nullptr, nullptr, nullptr, 0) == 0;
+#else
     return ProcCpuInfo::HasField(field);
+#endif
   } else if (method_ == kCpuInfoNone) {
     return false;
   } else {
