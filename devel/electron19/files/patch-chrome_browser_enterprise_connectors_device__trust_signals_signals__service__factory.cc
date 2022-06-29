--- chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc
@@ -15,7 +15,7 @@
 #include "chrome/browser/profiles/profile.h"
 #include "components/policy/core/common/management/management_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/check.h"
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/browser_signals_decorator.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -52,7 +52,7 @@ std::unique_ptr<SignalsService> CreateSignalsService(
   decorators.push_back(
       std::make_unique<ContentSignalsDecorator>(policy_blocklist_service));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   policy::CloudPolicyStore* store = nullptr;
 
   // Managed device.
