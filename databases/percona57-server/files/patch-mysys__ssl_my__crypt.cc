--- mysys_ssl/my_crypt.cc.orig	2019-05-16 05:06:00 UTC
+++ mysys_ssl/my_crypt.cc
@@ -30,7 +30,7 @@
 #include <boost/move/unique_ptr.hpp>
 #include <boost/core/noncopyable.hpp>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define EVP_CIPHER_CTX_buf_noconst(ctx) ((ctx)->buf)
 #define RAND_OpenSSL() RAND_SSLeay()
 #endif
@@ -95,7 +95,8 @@ MyEncryptionCTX::MyEncryptionCTX()
 MyEncryptionCTX::~MyEncryptionCTX()
 {
   
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x02090000fL)
   EVP_CIPHER_CTX_cleanup(ctx);
   delete ctx;
   ERR_remove_thread_state(0);
