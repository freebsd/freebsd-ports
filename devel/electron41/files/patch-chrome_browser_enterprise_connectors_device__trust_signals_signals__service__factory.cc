--- chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc
@@ -23,7 +23,7 @@
 #include "chrome/browser/enterprise/connectors/connectors_service.h"
 #endif  // BUILDFLAG(ENTERPRISE_CLOUD_CONTENT_ANALYSIS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/check.h"
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/browser_signals_decorator.h"
 #include "chrome/browser/enterprise/core/dependency_factory_impl.h"
@@ -63,7 +63,7 @@ std::unique_ptr<SignalsService> CreateSignalsService(P
           profile, ConnectorsServiceFactory::GetForBrowserContext(profile))));
 #endif  // BUILDFLAG(ENTERPRISE_CLOUD_CONTENT_ANALYSIS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
   policy::CloudPolicyManager* browser_policy_manager = nullptr;
   if (management_service->HasManagementAuthority(
