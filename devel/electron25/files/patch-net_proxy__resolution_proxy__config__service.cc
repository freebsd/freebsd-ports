--- net/proxy_resolution/proxy_config_service.cc.orig	2023-03-30 00:33:55 UTC
+++ net/proxy_resolution/proxy_config_service.cc
@@ -19,20 +19,20 @@
 #include "net/proxy_resolution/proxy_config_service_ios.h"
 #elif BUILDFLAG(IS_MAC)
 #include "net/proxy_resolution/proxy_config_service_mac.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/proxy_resolution/proxy_config_service_linux.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "net/proxy_resolution/proxy_config_service_android.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/traffic_annotation/network_traffic_annotation.h"
 #endif
 
 namespace net {
 
 namespace {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr net::NetworkTrafficAnnotationTag kSystemProxyConfigTrafficAnnotation =
     net::DefineNetworkTrafficAnnotation("proxy_config_system", R"(
       semantics {
@@ -108,7 +108,7 @@ ProxyConfigService::CreateSystemProxyConfigService(
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return std::make_unique<UnsetProxyConfigService>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ProxyConfigServiceLinux> linux_config_service(
       std::make_unique<ProxyConfigServiceLinux>());
 
