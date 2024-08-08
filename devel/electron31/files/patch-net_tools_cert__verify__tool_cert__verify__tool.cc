--- net/tools/cert_verify_tool/cert_verify_tool.cc.orig	2024-06-18 21:43:37 UTC
+++ net/tools/cert_verify_tool/cert_verify_tool.cc
@@ -34,7 +34,7 @@
 #include "third_party/boringssl/src/pki/trust_store.h"
 #include "third_party/boringssl/src/pki/trust_store_collection.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -66,7 +66,7 @@ void SetUpOnNetworkThread(
     base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
@@ -571,7 +571,7 @@ int main(int argc, char** argv) {
   std::string impls_str = command_line.GetSwitchValueASCII("impls");
   if (impls_str.empty()) {
     // Default value.
-#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
       BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(CHROME_ROOT_STORE_ONLY))
     impls_str = "platform,";
 #endif
