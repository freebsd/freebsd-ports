--- chrome/browser/extensions/api/api_browser_context_keyed_service_factories.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/extensions/api/api_browser_context_keyed_service_factories.cc
@@ -55,7 +55,7 @@
 
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_api.h"
 #include "chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_service.h"
 #endif
@@ -150,7 +150,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
   // These APIs are intentionally not supported on desktop Android.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   extensions::WebAuthenticationProxyAPI::GetFactoryInstance();
   extensions::WebAuthenticationProxyRegistrarFactory::GetInstance();
   extensions::WebAuthenticationProxyServiceFactory::GetInstance();
