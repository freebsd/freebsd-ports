--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2023-11-29 21:40:03 UTC
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -107,7 +107,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
   MessagingAPIMessageFilter::EnsureAssociatedFactoryBuilt();
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   OffscreenDocumentManager::GetFactory();
