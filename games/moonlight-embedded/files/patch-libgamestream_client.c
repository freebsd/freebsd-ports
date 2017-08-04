--- libgamestream/client.c.orig	2017-07-02 11:38:48 UTC
+++ libgamestream/client.c
@@ -494,7 +494,11 @@ int gs_pair(PSERVER_DATA server, char* pin) {
   RAND_bytes(client_secret_data, 16);
 
   const ASN1_BIT_STRING *asnSignature;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   X509_get0_signature(&asnSignature, NULL, cert);
+#else
+  asnSignature = cert->signature;
+#endif
 
   char challenge_response[16 + 256 + 16];
   char challenge_response_hash[32];
