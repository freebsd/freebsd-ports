--- chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc.orig	2022-05-19 05:17:36 UTC
+++ chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc
@@ -14,7 +14,7 @@
 #include "chrome/browser/enterprise/connectors/device_trust/signals/signals_service_impl.h"
 #include "chrome/browser/profiles/profile.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/check.h"
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/browser_signals_decorator.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -44,7 +44,7 @@ std::unique_ptr<SignalsService> CreateSignalsService(
   decorators.push_back(
       std::make_unique<ContentSignalsDecorator>(policy_blocklist_service));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   policy::ChromeBrowserPolicyConnector* browser_policy_connector =
       g_browser_process->browser_policy_connector();
   DCHECK(browser_policy_connector);
