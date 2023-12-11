--- chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc.orig	2023-10-19 19:58:04 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc
@@ -11,7 +11,7 @@
 #include "chrome/browser/profiles/profile.h"
 #include "components/keyed_service/core/keyed_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/browser/signing_key_policy_observer.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -42,7 +42,7 @@ DeviceTrustConnectorService* DeviceTrustConnectorServi
 
 bool DeviceTrustConnectorServiceFactory::ServiceIsCreatedWithBrowserContext()
     const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return IsDeviceTrustConnectorFeatureEnabled();
 #else
   return false;
@@ -80,7 +80,7 @@ DeviceTrustConnectorServiceFactory::BuildServiceInstan
   std::unique_ptr<DeviceTrustConnectorService> service =
       std::make_unique<DeviceTrustConnectorService>(profile->GetPrefs());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (IsDeviceTrustConnectorFeatureEnabled()) {
     auto* key_manager = g_browser_process->browser_policy_connector()
                             ->chrome_browser_cloud_management_controller()
