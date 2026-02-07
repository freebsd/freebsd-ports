--- libgamestream/client.c.orig	2024-02-20 04:01:31 UTC
+++ libgamestream/client.c
@@ -539,7 +539,15 @@ int gs_pair(PSERVER_DATA server, char* pin) {
   RAND_bytes(client_secret_data, sizeof(client_secret_data));
 
   const ASN1_BIT_STRING *asnSignature;
+#ifdef __FreeBSD__
+ #if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   X509_get0_signature(&asnSignature, NULL, cert);
+ #else
+  asnSignature = cert->signature;
+ #endif
+#else
+  X509_get0_signature(&asnSignature, NULL, cert);
+#endif
 
   challenge_response = malloc(16 + asnSignature->length + sizeof(client_secret_data));
   char challenge_response_hash[32];
