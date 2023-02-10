--- chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc
@@ -18,7 +18,7 @@
 #include "chrome/browser/profiles/profile.h"
 #include "components/policy/core/common/management/management_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/check.h"
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/browser_signals_decorator.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -54,7 +54,7 @@ std::unique_ptr<SignalsService> CreateSignalsService(P
       enterprise_signals::ContextInfoFetcher::CreateInstance(
           profile, ConnectorsServiceFactory::GetForBrowserContext(profile))));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   policy::CloudPolicyStore* store = nullptr;
 
   // Managed device.
