--- src/ptclib/pssl.cxx.orig	Wed Apr 16 04:00:19 2003
+++ src/ptclib/pssl.cxx	Wed Feb 22 09:24:08 2006
@@ -285,14 +285,22 @@
 
 PSSLPrivateKey::PSSLPrivateKey(const BYTE * keyData, PINDEX keySize)
 {
+#if (OPENSSL_VERSION_NUMBER < 0x0090801f)
   key = d2i_AutoPrivateKey(NULL, (BYTE **)&keyData, keySize);
+#else
+  key = d2i_AutoPrivateKey(NULL, (const unsigned char **)&keyData, keySize);
+#endif
 }
 
 
 PSSLPrivateKey::PSSLPrivateKey(const PBYTEArray & keyData)
 {
   const BYTE * keyPtr = keyData;
+#if (OPENSSL_VERSION_NUMBER < 0x0090801f)
   key = d2i_AutoPrivateKey(NULL, (BYTE **)&keyPtr, keyData.GetSize());
+#else
+  key = d2i_AutoPrivateKey(NULL, (const unsigned char **)&keyPtr, keyData.GetSize());
+#endif
 }
 
 
@@ -460,14 +468,22 @@
 
 PSSLCertificate::PSSLCertificate(const BYTE * certData, PINDEX certSize)
 {
+#if (OPENSSL_VERSION_NUMBER < 0x0090801f)
   certificate = d2i_X509(NULL, (unsigned char **)&certData, certSize);
+#else
+  certificate = d2i_X509(NULL, (const unsigned char **)&certData, certSize);
+#endif
 }
 
 
 PSSLCertificate::PSSLCertificate(const PBYTEArray & certData)
 {
   const BYTE * certPtr = certData;
+#if (OPENSSL_VERSION_NUMBER < 0x0090801f)
   certificate = d2i_X509(NULL, (unsigned char **)&certPtr, certData.GetSize());
+#else
+  certificate = d2i_X509(NULL, (const unsigned char **)&certPtr, certData.GetSize());
+#endif
 }
 
 
@@ -477,7 +493,11 @@
   PBase64::Decode(certStr, certData);
   if (certData.GetSize() > 0) {
     const BYTE * certPtr = certData;
+#if (OPENSSL_VERSION_NUMBER < 0x0090801f)
     certificate = d2i_X509(NULL, (unsigned char **)&certPtr, certData.GetSize());
+#else
+    certificate = d2i_X509(NULL, (const unsigned char **)&certPtr, certData.GetSize());
+#endif
   }
   else
     certificate = NULL;
