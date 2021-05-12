--- chrome/browser/device_identity/device_oauth2_token_service_factory.cc.orig	2021-04-14 01:08:39 UTC
+++ chrome/browser/device_identity/device_oauth2_token_service_factory.cc
@@ -30,7 +30,7 @@ std::unique_ptr<DeviceOAuth2TokenStore> CreatePlatform
   return std::make_unique<chromeos::DeviceOAuth2TokenStoreChromeOS>(
       local_state);
 #elif defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   DCHECK(
       base::FeatureList::IsEnabled(policy::features::kCBCMPolicyInvalidations));
   return std::make_unique<DeviceOAuth2TokenStoreDesktop>(local_state);
