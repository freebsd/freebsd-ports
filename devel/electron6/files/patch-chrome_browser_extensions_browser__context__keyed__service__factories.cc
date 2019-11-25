--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2019-09-10 11:13:39 UTC
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc
@@ -54,7 +54,7 @@
 #include "chrome/browser/chromeos/extensions/input_method_api.h"
 #include "chrome/browser/chromeos/extensions/media_player_api.h"
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #endif
 
@@ -92,7 +92,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
 #if defined(OS_CHROMEOS)
   extensions::InputImeAPI::GetFactoryInstance();
   extensions::InputMethodAPI::GetFactoryInstance();
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   extensions::InputImeAPI::GetFactoryInstance();
 #endif
   extensions::LanguageSettingsPrivateDelegateFactory::GetInstance();
