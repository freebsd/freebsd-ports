--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -206,11 +206,11 @@
 #include "chrome/browser/metrics/google_update_metrics_provider_mac.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/metrics/motherboard_metrics_provider.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/chrome_metrics_service_crash_reporter.h"
 #endif
 
@@ -223,19 +223,19 @@
 #include "chrome/browser/metrics/power/power_metrics_provider_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/bluetooth_metrics_provider.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/skills/skills_metrics_provider.h"
 #include "chrome/browser/ui/tabs/tab_metrics_provider.h"
 #include "components/skills/features.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/updates/update_metrics_provider.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -254,7 +254,7 @@ const char kCrashpadHistogramAllocatorName[] = "Crashp
 // Needs to be kept in sync with the writer in
 // third_party/crashpad/crashpad/handler/handler_main.cc.
 const char kCrashpadHistogramAllocatorName[] = "CrashpadMetrics";
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ChromeMetricsServiceCrashReporter& GetCrashReporter() {
   static base::NoDestructor<ChromeMetricsServiceCrashReporter> crash_reporter;
   return *crash_reporter;
@@ -564,7 +564,7 @@ void ChromeMetricsServiceClient::RegisterPrefs(PrefReg
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   metrics::structured::StructuredMetricsService::RegisterPrefs(registry);
 
 #if !BUILDFLAG(IS_CHROMEOS)
@@ -661,7 +661,7 @@ void ChromeMetricsServiceClient::OnEnvironmentUpdate(s
 void ChromeMetricsServiceClient::OnEnvironmentUpdate(std::string* environment) {
   // TODO(https://bugs.chromium.org/p/crashpad/issues/detail?id=135): call this
   // on Mac when the Crashpad API supports it.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Register the environment with the crash reporter. Note that there is a
   // window from startup to this point during which crash reports will not have
   // an environment set.
@@ -761,7 +761,7 @@ void ChromeMetricsServiceClient::Initialize() {
         this, local_state);
   }
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   metrics::structured::Recorder::GetInstance()->SetUiTaskRunner(
       base::SequencedTaskRunner::GetCurrentDefault());
 #endif
@@ -821,7 +821,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<metrics::CPUMetricsProvider>());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<metrics::MotherboardMetricsProvider>());
 #endif
@@ -917,7 +917,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
       std::make_unique<GoogleUpdateMetricsProviderMac>());
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<DesktopPlatformFeaturesMetricsProvider>());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -1016,7 +1016,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
       std::make_unique<HttpsEngagementMetricsProvider>());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<TabMetricsProvider>(
           g_browser_process->profile_manager()));
@@ -1038,7 +1038,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
       std::make_unique<PowerMetricsProvider>());
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       metrics::CreateDesktopSessionMetricsProvider());
   metrics_service_->RegisterMetricsProvider(
@@ -1244,7 +1244,7 @@ bool ChromeMetricsServiceClient::RegisterForProfileEve
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
   metrics::DesktopProfileSessionDurationsServiceFactory::GetForBrowserContext(
@@ -1595,7 +1595,7 @@ void ChromeMetricsServiceClient::CreateStructuredMetri
   recorder =
       std::make_unique<metrics::structured::AshStructuredMetricsRecorder>(
           cros_system_profile_provider_.get());
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
   // Make sure that Structured Metrics recording delegates have been created
   // before the service is created. This is handled in other places for ChromeOS
