--- net/cert/cert_verify_proc.cc.orig	2021-09-14 01:51:59 UTC
+++ net/cert/cert_verify_proc.cc
@@ -468,7 +468,7 @@ base::Value CertVerifyParams(X509Certificate* cert,
 
 }  // namespace
 
-#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 // static
 scoped_refptr<CertVerifyProc> CertVerifyProc::CreateSystemVerifyProc(
     scoped_refptr<CertNetFetcher> cert_net_fetcher) {
