--- chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc
@@ -57,7 +57,7 @@
 #include "chrome/browser/policy/browser_dm_token_storage_mac.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/browser_dm_token_storage_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -66,7 +66,7 @@
 #include "chrome/install_static/install_util.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/browser_context_delegate.h"
 #include "chrome/browser/enterprise/client_certificates/cert_utils.h"
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/device_trust_key_manager_impl.h"
@@ -111,7 +111,7 @@ void ChromeBrowserCloudManagementControllerDesktop::
 
 #if BUILDFLAG(IS_MAC)
   storage_delegate = std::make_unique<BrowserDMTokenStorageMac>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   storage_delegate = std::make_unique<BrowserDMTokenStorageLinux>();
 #elif BUILDFLAG(IS_WIN)
   storage_delegate = std::make_unique<BrowserDMTokenStorageWin>();
@@ -275,7 +275,7 @@ ChromeBrowserCloudManagementControllerDesktop::CreateD
 
 std::unique_ptr<enterprise_connectors::DeviceTrustKeyManager>
 ChromeBrowserCloudManagementControllerDesktop::CreateDeviceTrustKeyManager() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   auto* browser_dm_token_storage = BrowserDMTokenStorage::Get();
   auto* device_management_service = GetDeviceManagementService();
   auto shared_url_loader_factory = GetSharedURLLoaderFactory();
@@ -297,7 +297,7 @@ ChromeBrowserCloudManagementControllerDesktop::
 std::unique_ptr<client_certificates::CertificateProvisioningService>
 ChromeBrowserCloudManagementControllerDesktop::
     CreateCertificateProvisioningService() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (!certificate_store_) {
     certificate_store_ =
         std::make_unique<client_certificates::PrefsCertificateStore>(
