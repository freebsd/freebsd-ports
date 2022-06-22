--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2022-05-19 05:17:37 UTC
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -773,7 +773,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<DesktopPlatformFeaturesMetricsProvider>());
@@ -869,7 +869,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
       std::make_unique<PowerMetricsProvider>());
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       metrics::CreateDesktopSessionMetricsProvider());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX)
@@ -1045,7 +1045,7 @@ bool ChromeMetricsServiceClient::RegisterForProfileEve
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
