--- net/cert/cert_verifier.cc.orig	2023-05-25 00:42:00 UTC
+++ net/cert/cert_verifier.cc
@@ -40,7 +40,7 @@ class DefaultCertVerifyProcFactory : public net::CertV
     return CertVerifyProc::CreateBuiltinWithChromeRootStore(
         std::move(cert_net_fetcher), impl_params.crl_set,
         base::OptionalToPtr(impl_params.root_store_data));
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return CertVerifyProc::CreateBuiltinVerifyProc(std::move(cert_net_fetcher),
                                                    impl_params.crl_set);
 #else
