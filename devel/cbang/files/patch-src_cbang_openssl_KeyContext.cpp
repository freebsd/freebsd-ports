--- src/cbang/openssl/KeyContext.cpp.orig	2022-09-17 22:00:36 UTC
+++ src/cbang/openssl/KeyContext.cpp
@@ -121,8 +121,18 @@ void KeyContext::setRSAPubExp(uint64_t exp) {
   BigNum num;
   num.set(exp);
 
-  if (EVP_PKEY_CTX_set1_rsa_keygen_pubexp(ctx, num.get()) <= 0)
+#if OPENSSL_VERSION_NUMBER < 0x3000000fL
+  int ret = EVP_PKEY_CTX_set_rsa_keygen_pubexp(ctx, num.get());
+#else
+  int ret = EVP_PKEY_CTX_set1_rsa_keygen_pubexp(ctx, num.get());
+#endif
+
+  if (ret <= 0)
     THROW("Failed to set RSA public exponent: " << SSL::getErrorStr());
+
+#if OPENSSL_VERSION_NUMBER < 0x3000000fL
+  num.adopt(); // Don't deallocate
+#endif
 }
 
 
