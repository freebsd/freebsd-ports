--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2023-02-01 18:43:20 UTC
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -71,7 +71,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
   IdleManagerFactory::GetInstance();
   ManagementAPI::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   OffscreenDocumentManager::GetFactory();
