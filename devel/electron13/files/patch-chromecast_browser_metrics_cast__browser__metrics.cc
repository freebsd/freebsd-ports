--- chromecast/browser/metrics/cast_browser_metrics.cc.orig	2021-07-15 19:13:36 UTC
+++ chromecast/browser/metrics/cast_browser_metrics.cc
@@ -19,9 +19,9 @@
 #include "content/public/browser/network_service_instance.h"
 #include "content/public/common/content_switches.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chromecast/browser/metrics/external_metrics.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
 #include "chromecast/base/android/dumpstate_writer.h"
@@ -32,10 +32,10 @@ namespace metrics {
 
 const int kMetricsFetchTimeoutSeconds = 60;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kExternalUmaEventsRelativePath[] = "metrics/uma-events";
 const char kPlatformUmaEventsPath[] = "/data/share/chrome/metrics/uma-events";
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 CastBrowserMetrics::CastBrowserMetrics(
     std::unique_ptr<CastMetricsServiceClient> metrics_service_client) {
@@ -48,10 +48,10 @@ CastBrowserMetrics::CastBrowserMetrics(
 }
 
 CastBrowserMetrics::~CastBrowserMetrics() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   DCHECK(!external_metrics_);
   DCHECK(!platform_metrics_);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 }
 
 void CastBrowserMetrics::Initialize() {
@@ -61,9 +61,9 @@ void CastBrowserMetrics::Initialize() {
   auto stability_provider_unique_ptr =
       std::make_unique<CastStabilityMetricsProvider>(
           metrics_service, metrics_service_client_->pref_service());
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   auto* stability_provider = stability_provider_unique_ptr.get();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   metrics_service->RegisterMetricsProvider(
       std::move(stability_provider_unique_ptr));
 
@@ -84,7 +84,7 @@ void CastBrowserMetrics::Initialize() {
 
   metrics_service_client_->StartMetricsService();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS)A || defined(OS_BSD)
   // Start external metrics collection, which feeds data from external
   // processes into the main external metrics.
   external_metrics_ = new ExternalMetrics(
@@ -94,7 +94,7 @@ void CastBrowserMetrics::Initialize() {
   platform_metrics_ =
       new ExternalMetrics(stability_provider, kPlatformUmaEventsPath);
   platform_metrics_->Start();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 }
 
 void CastBrowserMetrics::Finalize() {
@@ -103,14 +103,14 @@ void CastBrowserMetrics::Finalize() {
   metrics_service_client_->GetMetricsService()->RecordCompletedSessionEnd();
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Stop metrics service cleanly before destructing CastMetricsServiceClient.
   // The pointer will be deleted in StopAndDestroy().
   external_metrics_->StopAndDestroy();
   external_metrics_ = nullptr;
   platform_metrics_->StopAndDestroy();
   platform_metrics_ = nullptr;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   metrics_service_client_->Finalize();
 }
@@ -126,13 +126,13 @@ void CastBrowserMetrics::CollectFinalMetricsForLog(
 }
 
 void CastBrowserMetrics::ProcessExternalEvents(base::OnceClosure cb) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   external_metrics_->ProcessExternalEvents(
       base::BindOnce(&ExternalMetrics::ProcessExternalEvents,
                      base::Unretained(platform_metrics_), std::move(cb)));
 #else
   std::move(cb).Run();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 }
 
 }  // namespace metrics
