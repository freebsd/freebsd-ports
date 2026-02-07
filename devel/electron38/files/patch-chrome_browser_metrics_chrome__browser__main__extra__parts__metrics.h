--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.h
@@ -29,7 +29,7 @@ class ProcessMonitor;
 class ProcessMonitor;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class PressureMetricsReporter;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -126,7 +126,7 @@ class ChromeBrowserMainExtraPartsMetrics : public Chro
   std::unique_ptr<web_app::SamplingMetricsProvider> web_app_metrics_provider_;
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reports pressure metrics.
   std::unique_ptr<PressureMetricsReporter> pressure_metrics_reporter_;
 #endif  // BUILDFLAG(IS_LINUX)
