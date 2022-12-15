--- chrome/browser/metrics/perf/cpu_identity.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/metrics/perf/cpu_identity.cc
@@ -106,7 +106,7 @@ CPUIdentity GetCPUIdentity() {
   result.release =
 #if BUILDFLAG(IS_CHROMEOS_ASH)
       base::SysInfo::KernelVersion();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
       base::SysInfo::OperatingSystemVersion();
 #else
 #error "Unsupported configuration"
