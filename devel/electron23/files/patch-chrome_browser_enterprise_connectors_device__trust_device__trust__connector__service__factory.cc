--- chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc
@@ -11,11 +11,11 @@
 #include "chrome/browser/profiles/profile.h"
 #include "components/keyed_service/core/keyed_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #if BUILDFLAG(IS_MAC)
 #include "chrome/browser/enterprise/connectors/device_trust/browser/mac_device_trust_connector_service.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/browser/browser_device_trust_connector_service.h"
 #endif  // BUILDFLAG(IS_MAC)
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -45,7 +45,7 @@ DeviceTrustConnectorService* DeviceTrustConnectorServi
 
 bool DeviceTrustConnectorServiceFactory::ServiceIsCreatedWithBrowserContext()
     const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return IsDeviceTrustConnectorFeatureEnabled();
 #else
   return false;
@@ -81,7 +81,7 @@ KeyedService* DeviceTrustConnectorServiceFactory::Buil
 
   DeviceTrustConnectorService* service = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (IsDeviceTrustConnectorFeatureEnabled()) {
     auto* key_manager = g_browser_process->browser_policy_connector()
                             ->chrome_browser_cloud_management_controller()
@@ -89,7 +89,7 @@ KeyedService* DeviceTrustConnectorServiceFactory::Buil
 #if BUILDFLAG(IS_MAC)
     service = new MacDeviceTrustConnectorService(
         key_manager, profile->GetPrefs(), g_browser_process->local_state());
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     service = new BrowserDeviceTrustConnectorService(key_manager,
                                                      profile->GetPrefs());
 #endif  // BUILDFLAG(IS_MAC)
