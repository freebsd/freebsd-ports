--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc
@@ -34,7 +34,7 @@
 #include "extensions/buildflags/buildflags.h"
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/signals_aggregator_factory.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -113,7 +113,7 @@ void CloudProfileReportingService::CreateReportSchedul
   params.profile_request_generator =
       std::make_unique<ChromeProfileRequestGenerator>(
           profile_->GetPath(), &delegate_factory,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           enterprise_signals::SignalsAggregatorFactory::GetForProfile(
               profile_));
 #else
