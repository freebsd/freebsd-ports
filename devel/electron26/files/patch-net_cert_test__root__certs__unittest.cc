--- net/cert/test_root_certs_unittest.cc.orig	2023-05-25 00:42:00 UTC
+++ net/cert/test_root_certs_unittest.cc
@@ -46,7 +46,7 @@ scoped_refptr<CertVerifyProc> CreateCertVerifyProc() {
   return CertVerifyProc::CreateBuiltinWithChromeRootStore(
       /*cert_net_fetcher=*/nullptr, CRLSet::BuiltinCRLSet().get(),
       /*root_store_data=*/nullptr);
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return CertVerifyProc::CreateBuiltinVerifyProc(/*cert_net_fetcher=*/nullptr,
                                                  CRLSet::BuiltinCRLSet().get());
 #else
