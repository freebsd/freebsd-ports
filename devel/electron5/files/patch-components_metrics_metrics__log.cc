--- components/metrics/metrics_log.cc.orig	2019-04-08 08:32:49 UTC
+++ components/metrics/metrics_log.cc
@@ -198,7 +198,7 @@ void MetricsLog::RecordCoreSystemProfile(MetricsServic
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if defined(OS_CHROMEOS)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());
