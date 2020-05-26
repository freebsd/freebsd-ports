--- mysys_ssl/my_crypt.cc.orig	2019-05-16 05:06:00 UTC
+++ mysys_ssl/my_crypt.cc
@@ -26,7 +26,7 @@
 #include <boost/move/unique_ptr.hpp>
 #include <boost/core/noncopyable.hpp>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define EVP_CIPHER_CTX_buf_noconst(ctx) ((ctx)->buf)
 #define RAND_OpenSSL() RAND_SSLeay()
 #endif
@@ -80,7 +80,7 @@ class MyEncryptionCTX : private boost::noncopyable (pr
 
 MyEncryptionCTX::MyEncryptionCTX()
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   ctx= new EVP_CIPHER_CTX();
   EVP_CIPHER_CTX_init(ctx);
 #else
@@ -91,7 +91,8 @@ MyEncryptionCTX::MyEncryptionCTX()
 MyEncryptionCTX::~MyEncryptionCTX()
 {
   
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x02090000fL)
   EVP_CIPHER_CTX_cleanup(ctx);
   delete ctx;
   ERR_remove_thread_state(0);
@@ -340,7 +341,7 @@ int my_aes_crypt(const my_aes_mode mode, int flags,
   res2= my_aes_crypt_finish(ctx, dst + d1, &d2);
   if (res1 || res2)
   {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     /* in case of failure clear error queue */
     ERR_remove_thread_state(0);
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
