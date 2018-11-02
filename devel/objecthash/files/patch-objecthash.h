--- objecthash.h.orig	2018-09-25 20:58:11 UTC
+++ objecthash.h
@@ -8,9 +8,7 @@ extern "C" {
 
 typedef unsigned char byte;
 
-static const int HASH_SIZE = SHA256_DIGEST_LENGTH;
-
-typedef byte hash[HASH_SIZE];
+typedef byte hash[SHA256_DIGEST_LENGTH];
 typedef SHA256_CTX hash_ctx;
 
 bool python_json_hash(const char *json, hash h);
