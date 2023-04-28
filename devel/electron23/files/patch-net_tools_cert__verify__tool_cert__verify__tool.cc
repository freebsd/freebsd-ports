--- net/tools/cert_verify_tool/cert_verify_tool.cc.orig	2022-06-17 14:20:10 UTC
+++ net/tools/cert_verify_tool/cert_verify_tool.cc
@@ -30,7 +30,7 @@
 #include "net/url_request/url_request_context_builder.h"
 #include "net/url_request/url_request_context_getter.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "net/proxy_resolution/proxy_config.h"
 #include "net/proxy_resolution/proxy_config_service_fixed.h"
 #endif
@@ -60,7 +60,7 @@ void SetUpOnNetworkThread(
     base::WaitableEvent* initialization_complete_event) {
   net::URLRequestContextBuilder url_request_context_builder;
   url_request_context_builder.set_user_agent(GetUserAgent());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   //
@@ -217,7 +217,7 @@ std::unique_ptr<CertVerifyImpl> CreateCertVerifyImplFr
     base::StringPiece impl_name,
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher,
     RootStoreType root_store_type) {
-#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
   if (impl_name == "platform") {
     if (root_store_type != RootStoreType::kSystem) {
       std::cerr << "WARNING: platform verifier not supported with "
@@ -474,7 +474,7 @@ int main(int argc, char** argv) {
   std::string impls_str = command_line.GetSwitchValueASCII("impls");
   if (impls_str.empty()) {
     // Default value.
-#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
     impls_str = "platform,";
 #endif
     impls_str += "builtin,pathbuilder";
