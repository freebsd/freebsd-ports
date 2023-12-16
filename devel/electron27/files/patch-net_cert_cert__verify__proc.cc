--- net/cert/cert_verify_proc.cc.orig	2023-05-25 00:42:00 UTC
+++ net/cert/cert_verify_proc.cc
@@ -409,7 +409,7 @@ base::Value::Dict CertVerifyParams(
 
 }  // namespace
 
-#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+#if !(BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
       BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(CHROME_ROOT_STORE_ONLY))
 // static
 scoped_refptr<CertVerifyProc> CertVerifyProc::CreateSystemVerifyProc(
