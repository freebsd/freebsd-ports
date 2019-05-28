--- electron/atom/browser/io_thread.cc.orig	2019-05-23 00:43:26 UTC
+++ electron/atom/browser/io_thread.cc
@@ -18,7 +18,7 @@
 #include "net/cert_net/nss_ocsp.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 #include "net/cert/cert_net_fetcher.h"
 #include "net/cert_net/cert_net_fetcher_impl.h"
 #endif
@@ -96,7 +96,7 @@ void IOThread::Init() {
 #if defined(USE_NSS_CERTS)
   net::SetURLRequestContextForNSSHttpIO(url_request_context_.get());
 #endif
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   net::SetGlobalCertNetFetcher(
       net::CreateCertNetFetcher(url_request_context_.get()));
 #endif
@@ -106,7 +106,7 @@ void IOThread::CleanUp() {
 #if defined(USE_NSS_CERTS)
   net::SetURLRequestContextForNSSHttpIO(nullptr);
 #endif
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   net::ShutdownGlobalCertNetFetcher();
 #endif
   // Explicitly release before the IO thread gets destroyed.
