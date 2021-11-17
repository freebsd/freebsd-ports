--- src/core/tsi/alts/crypt/aes_gcm.cc.orig	2020-12-01 19:24:28 UTC
+++ src/core/tsi/alts/crypt/aes_gcm.cc
@@ -185,7 +185,7 @@ static grpc_status_code aes_gcm_derive_aead_key(uint8_
                                                 const uint8_t* kdf_counter) {
   unsigned char buf[EVP_MAX_MD_SIZE];
   unsigned char ctr = 1;
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
   HMAC_CTX hmac;
   HMAC_CTX_init(&hmac);
   if (!HMAC_Init_ex(&hmac, kdf_key, kKdfKeyLen, EVP_sha256(), nullptr) ||
