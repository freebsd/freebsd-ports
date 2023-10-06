--- base/system/sys_info_posix.cc.orig	2023-08-10 01:48:31 UTC
+++ base/system/sys_info_posix.cc
@@ -117,7 +117,7 @@ bool GetDiskSpaceInfo(const base::FilePath& path,
 
 namespace base {
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 int SysInfo::NumberOfProcessors() {
 #if BUILDFLAG(IS_MAC)
   absl::optional<int> number_of_physical_cores =
@@ -161,7 +161,7 @@ int SysInfo::NumberOfProcessors() {
 
   return num_cpus;
 }
-#endif  // !BUILDFLAG(IS_OPENBSD)
+#endif  // !BUILDFLAG(IS_BSD)
 
 // static
 uint64_t SysInfo::AmountOfVirtualMemory() {
@@ -251,6 +251,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
