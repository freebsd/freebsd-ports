--- Crypto/src/DigestEngine.cpp.orig	2017-02-22 13:17:54 UTC
+++ Crypto/src/DigestEngine.cpp
@@ -50,7 +50,7 @@ std::size_t DigestEngine::digestLength()
 
 void DigestEngine::reset()
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	EVP_MD_CTX_free(_pContext);
 	_pContext = EVP_MD_CTX_create();
 #else
