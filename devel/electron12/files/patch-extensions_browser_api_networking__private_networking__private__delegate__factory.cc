--- extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2021-04-14 01:08:49 UTC
+++ extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -12,7 +12,7 @@
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif defined(OS_WIN) || defined(OS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -62,7 +62,7 @@ KeyedService* NetworkingPrivateDelegateFactory::BuildS
   NetworkingPrivateDelegate* delegate;
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   delegate = new NetworkingPrivateChromeOS(browser_context);
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   delegate = new NetworkingPrivateLinux();
 #elif defined(OS_WIN) || defined(OS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
