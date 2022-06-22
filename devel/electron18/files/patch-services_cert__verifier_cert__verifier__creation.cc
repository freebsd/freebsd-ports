--- services/cert_verifier/cert_verifier_creation.cc.orig	2022-05-19 05:17:45 UTC
+++ services/cert_verifier/cert_verifier_creation.cc
@@ -86,7 +86,7 @@ scoped_refptr<net::CertVerifyProc> CreateCertVerifyPro
 scoped_refptr<net::CertVerifyProc> CreateOldDefaultWithoutCaching(
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher) {
   scoped_refptr<net::CertVerifyProc> verify_proc;
-#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   verify_proc =
       net::CertVerifyProc::CreateBuiltinVerifyProc(std::move(cert_net_fetcher));
 #else
@@ -104,7 +104,7 @@ scoped_refptr<net::CertVerifyProc> CreateNewDefaultWit
     scoped_refptr<net::CertNetFetcher> cert_net_fetcher) {
   scoped_refptr<net::CertVerifyProc> verify_proc;
 #if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   verify_proc = net::CreateCertVerifyProcBuiltin(
       std::move(cert_net_fetcher), net::CreateSslSystemTrustStoreChromeRoot());
 #elif BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
@@ -122,7 +122,8 @@ bool IsUsingCertNetFetcher() {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) ||      \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||       \
     BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED) || \
-    BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
+    BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED) || \
+    BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
