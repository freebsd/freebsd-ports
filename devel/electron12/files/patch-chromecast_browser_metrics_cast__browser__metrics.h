--- chromecast/browser/metrics/cast_browser_metrics.h.orig	2021-04-14 01:08:44 UTC
+++ chromecast/browser/metrics/cast_browser_metrics.h
@@ -38,10 +38,10 @@ class CastBrowserMetrics {
  private:
   std::unique_ptr<CastMetricsServiceClient> metrics_service_client_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   ExternalMetrics* external_metrics_ = nullptr;
   ExternalMetrics* platform_metrics_ = nullptr;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   DISALLOW_COPY_AND_ASSIGN(CastBrowserMetrics);
 };
