--- net/cert/cert_verify_proc.h.orig	2022-05-11 07:16:53 UTC
+++ net/cert/cert_verify_proc.h
@@ -65,7 +65,7 @@ class NET_EXPORT CertVerifyProc
     kMaxValue = kChainLengthOne
   };
 
-#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   // Creates and returns a CertVerifyProc that uses the system verifier.
   // |cert_net_fetcher| may not be used, depending on the implementation.
   static scoped_refptr<CertVerifyProc> CreateSystemVerifyProc(
