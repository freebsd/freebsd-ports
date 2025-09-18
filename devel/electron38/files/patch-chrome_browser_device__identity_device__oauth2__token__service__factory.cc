--- chrome/browser/device_identity/device_oauth2_token_service_factory.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/device_identity/device_oauth2_token_service_factory.cc
@@ -26,7 +26,7 @@ std::unique_ptr<DeviceOAuth2TokenStore> CreatePlatform
 #if BUILDFLAG(IS_CHROMEOS)
   return std::make_unique<chromeos::DeviceOAuth2TokenStoreChromeOS>(
       local_state);
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<DeviceOAuth2TokenStoreDesktop>(local_state);
 #else
   NOTREACHED();
