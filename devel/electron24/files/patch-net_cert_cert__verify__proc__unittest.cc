--- net/cert/cert_verify_proc_unittest.cc.orig	2023-03-30 00:33:54 UTC
+++ net/cert/cert_verify_proc_unittest.cc
@@ -270,7 +270,7 @@ const std::vector<CertVerifyProcType> kAllCertVerifier
 #if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED)
     CERT_VERIFY_PROC_BUILTIN_CHROME_ROOTS
 #endif
-#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     CERT_VERIFY_PROC_BUILTIN
 #else
 #error Unsupported platform
