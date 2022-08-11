--- net/proxy_resolution/configured_proxy_resolution_service.cc.orig	2022-05-19 05:17:44 UTC
+++ net/proxy_resolution/configured_proxy_resolution_service.cc
@@ -52,7 +52,7 @@
 #elif BUILDFLAG(IS_MAC)
 #include "net/proxy_resolution/proxy_config_service_mac.h"
 #include "net/proxy_resolution/proxy_resolver_mac.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/proxy_resolution/proxy_config_service_linux.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "net/proxy_resolution/proxy_config_service_android.h"
@@ -64,7 +64,7 @@ namespace net {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr net::NetworkTrafficAnnotationTag kSystemProxyConfigTrafficAnnotation =
     net::DefineNetworkTrafficAnnotation("proxy_config_system", R"(
       semantics {
@@ -1422,7 +1422,7 @@ ConfiguredProxyResolutionService::CreateSystemProxyCon
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return std::make_unique<UnsetProxyConfigService>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ProxyConfigServiceLinux> linux_config_service(
       new ProxyConfigServiceLinux());
 
