--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -195,7 +195,7 @@
 #include "chrome/notification_helper/notification_helper_constants.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/metrics/motherboard_metrics_provider.h"
 #endif
 
@@ -212,7 +212,7 @@
 #include "chrome/browser/metrics/power/power_metrics_provider_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/bluetooth_metrics_provider.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -534,7 +534,7 @@ void ChromeMetricsServiceClient::RegisterPrefs(PrefReg
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   metrics::structured::StructuredMetricsService::RegisterPrefs(registry);
 
 #if !BUILDFLAG(IS_CHROMEOS_ASH)
@@ -706,7 +706,7 @@ void ChromeMetricsServiceClient::Initialize() {
     RegisterUKMProviders();
   }
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   metrics::structured::Recorder::GetInstance()->SetUiTaskRunner(
       base::SequencedTaskRunner::GetCurrentDefault());
 #endif
@@ -757,7 +757,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<metrics::CPUMetricsProvider>());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<metrics::MotherboardMetricsProvider>());
 #endif
@@ -842,7 +842,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<DesktopPlatformFeaturesMetricsProvider>());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) ||
@@ -944,7 +944,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
       std::make_unique<PowerMetricsProvider>());
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       metrics::CreateDesktopSessionMetricsProvider());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX)
@@ -1131,7 +1131,7 @@ bool ChromeMetricsServiceClient::RegisterForProfileEve
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
   metrics::DesktopProfileSessionDurationsServiceFactory::GetForBrowserContext(
@@ -1465,7 +1465,7 @@ void ChromeMetricsServiceClient::CreateStructuredMetri
   recorder =
       std::make_unique<metrics::structured::AshStructuredMetricsRecorder>(
           cros_system_profile_provider_.get());
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
   // Make sure that Structured Metrics recording delegates have been created
   // before the service is created. This is handled in other places for ChromeOS
