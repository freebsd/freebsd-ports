--- libgamestream/client.c.orig	2023-09-01 23:40:56 UTC
+++ libgamestream/client.c
@@ -537,7 +537,11 @@ int gs_pair(PSERVER_DATA server, char* pin) {
   RAND_bytes(client_secret_data, sizeof(client_secret_data));
 
   const ASN1_BIT_STRING *asnSignature;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   X509_get0_signature(&asnSignature, NULL, cert);
+#else
+  asnSignature = cert->signature;
+#endif
 
   char challenge_response[16 + SIGNATURE_LEN + sizeof(client_secret_data)];
   char challenge_response_hash[32];
