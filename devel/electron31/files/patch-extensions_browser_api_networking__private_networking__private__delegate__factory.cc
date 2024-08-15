--- extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2023-10-19 19:58:24 UTC
+++ extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -14,7 +14,7 @@
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
 #include "extensions/browser/api/networking_private/networking_private_lacros.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -67,7 +67,7 @@ NetworkingPrivateDelegateFactory::BuildServiceInstance
   delegate = std::make_unique<NetworkingPrivateChromeOS>(browser_context);
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   delegate = std::make_unique<NetworkingPrivateLacros>(browser_context);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   delegate = std::make_unique<NetworkingPrivateLinux>();
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
