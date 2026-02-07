--- components/supervised_user/core/browser/supervised_user_metrics_service.cc.orig	2025-06-30 07:04:30 UTC
+++ components/supervised_user/core/browser/supervised_user_metrics_service.cc
@@ -68,7 +68,7 @@ SupervisedUserMetricsService::SupervisedUserMetricsSer
       extensions_metrics_delegate_(std::move(extensions_metrics_delegate)) {
   DCHECK(pref_service_);
   supervised_user_service_observation_.Observe(&supervised_user_service);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(extensions_metrics_delegate_)
       << "Extensions metrics delegate must exist on Win/Linux/Mac";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
