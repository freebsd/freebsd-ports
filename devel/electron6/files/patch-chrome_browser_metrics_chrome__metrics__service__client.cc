--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2019-09-10 11:13:40 UTC
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -902,7 +902,7 @@ bool ChromeMetricsServiceClient::RegisterForProfileEve
   }
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
   metrics::DesktopProfileSessionDurationsServiceFactory::GetForBrowserContext(
