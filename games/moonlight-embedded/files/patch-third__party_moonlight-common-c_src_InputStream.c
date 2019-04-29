--- third_party/moonlight-common-c/src/InputStream.c.orig	2019-04-29 17:05:00 UTC
+++ third_party/moonlight-common-c/src/InputStream.c
@@ -35,7 +35,7 @@ typedef struct _PACKET_HOLDER {
     LINKED_BLOCKING_QUEUE_ENTRY entry;
 } PACKET_HOLDER, *PPACKET_HOLDER;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define EVP_CIPHER_CTX_reset(x) EVP_CIPHER_CTX_cleanup(x); EVP_CIPHER_CTX_init(x)
 #endif
 
