--- components/system_cpu/cpu_probe.cc.orig	2024-02-21 00:20:43 UTC
+++ components/system_cpu/cpu_probe.cc
@@ -30,6 +30,9 @@ std::unique_ptr<CpuProbe> CpuProbe::Create() {
   return CpuProbeWin::Create();
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create();
+#elif BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return nullptr;
 #else
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
