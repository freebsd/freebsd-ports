--- chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc.orig	2023-10-19 19:58:05 UTC
+++ chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc
@@ -49,7 +49,7 @@
 #include "chrome/browser/policy/browser_dm_token_storage_mac.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/browser_dm_token_storage_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -58,7 +58,7 @@
 #include "chrome/install_static/install_util.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_features.h"  // nogncheck
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/device_trust_key_manager_impl.h"
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/key_rotation_launcher.h"
@@ -91,7 +91,7 @@ void ChromeBrowserCloudManagementControllerDesktop::
 
 #if BUILDFLAG(IS_MAC)
   storage_delegate = std::make_unique<BrowserDMTokenStorageMac>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   storage_delegate = std::make_unique<BrowserDMTokenStorageLinux>();
 #elif BUILDFLAG(IS_WIN)
   storage_delegate = std::make_unique<BrowserDMTokenStorageWin>();
@@ -246,7 +246,7 @@ ChromeBrowserCloudManagementControllerDesktop::CreateC
 
 std::unique_ptr<enterprise_connectors::DeviceTrustKeyManager>
 ChromeBrowserCloudManagementControllerDesktop::CreateDeviceTrustKeyManager() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (enterprise_connectors::IsDeviceTrustConnectorFeatureEnabled()) {
     auto* browser_dm_token_storage = BrowserDMTokenStorage::Get();
     auto* device_management_service = GetDeviceManagementService();
