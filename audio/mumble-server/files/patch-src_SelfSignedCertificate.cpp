--- src/SelfSignedCertificate.cpp.orig	2023-06-11 17:43:07 UTC
+++ src/SelfSignedCertificate.cpp
@@ -45,10 +45,12 @@ bool SelfSignedCertificate::generate(CertificateType c
 	QString commonName;
 	bool isServerCert = certificateType == CertificateTypeServerCertificate;
 
+#ifdef CRYPTO_MEM_CHECK_ON
 	if (CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON) == -1) {
 		ok = false;
 		goto out;
 	}
+#endif
 
 	x509 = X509_new();
 	if (x509 == NULL) {
