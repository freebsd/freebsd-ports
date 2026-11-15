--- base/system/sys_info_posix.cc.orig	2026-06-23 23:37:18 UTC
+++ base/system/sys_info_posix.cc
@@ -59,7 +59,11 @@ base::ByteSize AmountOfVirtualMemory() {
   if (result != 0) {
     NOTREACHED();
   }
+#if BUILDFLAG(IS_FREEBSD)
+  return base::ByteSize(limit.rlim_cur == RLIM_INFINITY ? 0 : base::checked_cast<uint64_t>(limit.rlim_cur));
+#else
   return base::ByteSize(limit.rlim_cur == RLIM_INFINITY ? 0 : limit.rlim_cur);
+#endif
 }
 using LazyVirtualMemory =
     base::internal::LazySysInfoValue<base::ByteSize, AmountOfVirtualMemory>;
@@ -110,7 +114,7 @@ namespace base {
 
 namespace base {
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 // static
 int SysInfo::NumberOfProcessors() {
 #if BUILDFLAG(IS_MAC)
@@ -166,7 +170,7 @@ int SysInfo::NumberOfProcessors() {
 
   return cached_num_cpus;
 }
-#endif  // !BUILDFLAG(IS_OPENBSD)
+#endif  // !BUILDFLAG(IS_BSD)
 
 // static
 ByteSize SysInfo::AmountOfVirtualMemory() {
@@ -275,6 +279,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
