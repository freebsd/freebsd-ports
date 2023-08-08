--- net/cert/cert_verify_proc_unittest.cc.orig	2023-02-01 18:43:23 UTC
+++ net/cert/cert_verify_proc_unittest.cc
@@ -269,7 +269,7 @@ const std::vector<CertVerifyProcType> kAllCertVerifier
 #if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED)
     CERT_VERIFY_PROC_BUILTIN_CHROME_ROOTS
 #endif
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     CERT_VERIFY_PROC_BUILTIN
 #else
 #error Unsupported platform
