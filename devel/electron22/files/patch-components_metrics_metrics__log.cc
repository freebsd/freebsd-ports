--- components/metrics/metrics_log.cc.orig	2022-11-30 08:12:58 UTC
+++ components/metrics/metrics_log.cc
@@ -54,7 +54,7 @@
 #include "base/win/current_module.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -144,7 +144,7 @@ void RecordCurrentTime(
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 metrics::SystemProfileProto::OS::XdgSessionType ToProtoSessionType(
     base::nix::SessionType session_type) {
   switch (session_type) {
@@ -415,7 +415,7 @@ void MetricsLog::RecordCoreSystemProfile(
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());
@@ -432,7 +432,7 @@ void MetricsLog::RecordCoreSystemProfile(
   os->set_build_number(base::SysInfo::GetIOSBuildNumber());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env = base::Environment::Create();
   os->set_xdg_session_type(ToProtoSessionType(base::nix::GetSessionType(*env)));
   os->set_xdg_current_desktop(
