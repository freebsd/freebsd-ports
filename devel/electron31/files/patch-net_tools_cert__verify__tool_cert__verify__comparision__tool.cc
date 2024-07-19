--- net/tools/cert_verify_tool/cert_verify_comparision_tool.cc.orig	2024-06-18 21:43:37 UTC
+++ net/tools/cert_verify_tool/cert_verify_comparision_tool.cc
@@ -36,7 +36,7 @@
 #include "net/url_request/url_request_context_builder.h"
 #include "net/url_request/url_request_context_getter.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -56,7 +56,7 @@ void SetUpOnNetworkThread(
     base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
@@ -124,7 +124,7 @@ std::unique_ptr<CertVerifyImpl> CreateCertVerifyImplFr
 std::unique_ptr<CertVerifyImpl> CreateCertVerifyImplFromName(
     std::string_view impl_name,
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher) {
-#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
       BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(CHROME_ROOT_STORE_ONLY))
   if (impl_name == "platform") {
     return std::make_unique<CertVerifyImpl>(
