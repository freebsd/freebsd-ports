--- components/power_metrics/energy_metrics_provider.cc.orig	2023-08-10 01:48:41 UTC
+++ components/power_metrics/energy_metrics_provider.cc
@@ -9,6 +9,8 @@
 #include "components/power_metrics/energy_metrics_provider_win.h"
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #include "components/power_metrics/energy_metrics_provider_linux.h"
+#elif BUILDFLAG(IS_BSD)
+#include "base/notreached.h"
 #endif  // BUILDFLAG(IS_WIN)
 
 namespace power_metrics {
@@ -22,6 +24,9 @@ std::unique_ptr<EnergyMetricsProvider> EnergyMetricsPr
   return EnergyMetricsProviderWin::Create();
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   return EnergyMetricsProviderLinux::Create();
+#elif BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return nullptr;
 #else
   return nullptr;
 #endif  // BUILDFLAG(IS_WIN)
