--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc
@@ -53,7 +53,7 @@
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 #include "ppapi/buildflags/buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/system_indicator/system_indicator_manager_factory.h"
 #endif
 
@@ -122,7 +122,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
   extensions::SettingsPrivateEventRouterFactory::GetInstance();
   extensions::SettingsOverridesAPI::GetFactoryInstance();
   extensions::SidePanelService::GetFactoryInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   extensions::SystemIndicatorManagerFactory::GetInstance();
 #endif
   extensions::TabGroupsEventRouterFactory::GetInstance();
