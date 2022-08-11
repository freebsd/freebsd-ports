--- content/browser/compute_pressure/cpu_probe.cc.orig	2022-05-19 03:45:28 UTC
+++ content/browser/compute_pressure/cpu_probe.cc
@@ -53,6 +53,7 @@ std::unique_ptr<CpuProbe> CpuProbe::Create() {
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   return CpuProbeLinux::Create();
 #else
+  NOTIMPLEMENTED();
   return std::make_unique<NullCpuProbe>();
 #endif  // BUILDFLAG(IS_ANDROID)
 }
