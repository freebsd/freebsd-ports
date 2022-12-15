--- base/system/sys_info_posix.cc.orig	2022-08-31 12:19:35 UTC
+++ base/system/sys_info_posix.cc
@@ -37,7 +37,7 @@
 
 namespace {
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 int NumberOfProcessors() {
   // sysconf returns the number of "logical" (not "physical") processors on both
   // Mac and Linux.  So we get the number of max available "logical" processors.
@@ -77,7 +77,7 @@ int NumberOfProcessors() {
 
 base::LazyInstance<base::internal::LazySysInfoValue<int, NumberOfProcessors>>::
     Leaky g_lazy_number_of_processors = LAZY_INSTANCE_INITIALIZER;
-#endif  // !BUILDFLAG(IS_OPENBSD)
+#endif  // !BUILDFLAG(IS_BSD)
 
 uint64_t AmountOfVirtualMemory() {
   struct rlimit limit;
@@ -144,11 +144,11 @@ bool GetDiskSpaceInfo(const base::FilePath& path,
 
 namespace base {
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
-#endif  // !BUILDFLAG(IS_OPENBSD)
+#endif  // !BUILDFLAG(IS_BSD)
 
 // static
 uint64_t SysInfo::AmountOfVirtualMemory() {
@@ -238,6 +238,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
