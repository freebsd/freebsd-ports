--- chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc.orig	2024-08-14 20:54:34 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/profiles/profile.h"
 #include "components/keyed_service/core/keyed_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/browser/signing_key_policy_observer.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -40,7 +40,7 @@ bool DeviceTrustConnectorServiceFactory::ServiceIsCrea
 
 bool DeviceTrustConnectorServiceFactory::ServiceIsCreatedWithBrowserContext()
     const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
@@ -84,7 +84,7 @@ DeviceTrustConnectorServiceFactory::BuildServiceInstan
   std::unique_ptr<DeviceTrustConnectorService> service =
       std::make_unique<DeviceTrustConnectorService>(profile->GetPrefs());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   auto* key_manager = g_browser_process->browser_policy_connector()
                           ->chrome_browser_cloud_management_controller()
                           ->GetDeviceTrustKeyManager();
