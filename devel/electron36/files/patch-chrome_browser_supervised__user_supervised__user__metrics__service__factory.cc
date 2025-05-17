--- chrome/browser/supervised_user/supervised_user_metrics_service_factory.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/supervised_user/supervised_user_metrics_service_factory.cc
@@ -14,7 +14,7 @@
 #include "components/supervised_user/core/browser/supervised_user_service.h"
 #include "content/public/browser/browser_context.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/linux_mac_windows/supervised_user_extensions_metrics_delegate_impl.h"
 #endif
 
@@ -62,7 +62,7 @@ SupervisedUserMetricsServiceFactory::BuildServiceInsta
   std::unique_ptr<supervised_user::SupervisedUserMetricsService ::
                       SupervisedUserMetricsServiceExtensionDelegate>
       extensions_metrics_delegate = nullptr;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   extensions_metrics_delegate =
       std::make_unique<SupervisedUserExtensionsMetricsDelegateImpl>(
           extensions::ExtensionRegistry::Get(profile), profile);
