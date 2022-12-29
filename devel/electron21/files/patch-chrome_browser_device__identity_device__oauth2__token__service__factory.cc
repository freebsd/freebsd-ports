--- chrome/browser/device_identity/device_oauth2_token_service_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/device_identity/device_oauth2_token_service_factory.cc
@@ -28,7 +28,7 @@ std::unique_ptr<DeviceOAuth2TokenStore> CreatePlatform
   return std::make_unique<chromeos::DeviceOAuth2TokenStoreChromeOS>(
       local_state);
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   return std::make_unique<DeviceOAuth2TokenStoreDesktop>(local_state);
 #else
   NOTREACHED();
