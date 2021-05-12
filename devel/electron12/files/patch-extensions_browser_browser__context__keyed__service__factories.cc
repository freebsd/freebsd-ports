--- extensions/browser/browser_context_keyed_service_factories.cc.orig	2021-04-14 01:08:49 UTC
+++ extensions/browser/browser_context_keyed_service_factories.cc
@@ -88,7 +88,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
   HidDeviceManager::GetFactoryInstance();
   IdleManagerFactory::GetInstance();
   ManagementAPI::GetFactoryInstance();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_MAC)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
