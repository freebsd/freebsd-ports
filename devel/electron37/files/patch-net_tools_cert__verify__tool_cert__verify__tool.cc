--- net/tools/cert_verify_tool/cert_verify_tool.cc.orig	2025-06-30 07:04:30 UTC
+++ net/tools/cert_verify_tool/cert_verify_tool.cc
@@ -35,7 +35,7 @@
 #include "third_party/boringssl/src/pki/trust_store.h"
 #include "third_party/boringssl/src/pki/trust_store_collection.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -67,7 +67,7 @@ void SetUpOnNetworkThread(
     base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
