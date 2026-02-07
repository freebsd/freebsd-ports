--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service_factory.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service_factory.cc
@@ -10,7 +10,7 @@
 #include "components/enterprise/browser/reporting/report_scheduler.h"
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/signals_aggregator_factory.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
@@ -48,7 +48,7 @@ CloudProfileReportingServiceFactory::CloudProfileRepor
                                  ProfileSelections::BuildForRegularProfile()) {
   DependsOn(enterprise::ProfileIdServiceFactory::GetInstance());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Depends on this service because
   // `CloudProfileReportingService.profile_request_generator_` has a dependency
   // on it.
