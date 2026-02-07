--- objecthash.c.orig	2018-09-25 21:01:54 UTC
+++ objecthash.c
@@ -13,7 +13,7 @@
 
 #include "objecthash.h"
 
-bool object_hash(/*const*/ json_object *j, byte hash[HASH_SIZE]);
+bool object_hash(/*const*/ json_object *j, byte hash[SHA256_DIGEST_LENGTH]);
 
 static void hash_update(hash_ctx * const c, const byte * const b,
                         const size_t l) {
@@ -45,7 +45,7 @@ static int dict_comp(const void *a, const void *b) {
   return memcmp(a, b, 2 * sizeof(hash));
 }
 
-static bool object_hash_str(const char *str, size_t len, byte hash[HASH_SIZE]) {
+static bool object_hash_str(const char *str, size_t len, byte hash[SHA256_DIGEST_LENGTH]) {
   hash_bytes('u', (const byte *)str, len, hash);
   return true;
 }
@@ -147,7 +147,7 @@ static bool object_hash_list(json_object *l, hash h) {
 
   int len = json_object_array_length(l);
   for (int n = 0; n < len; ++n) {
-    byte ihash[HASH_SIZE];
+    byte ihash[SHA256_DIGEST_LENGTH];
     if (!object_hash(json_object_array_get_idx(l, n), ihash))
       return false;
     hash_update(&ctx, ihash, sizeof ihash);
@@ -157,7 +157,7 @@ static bool object_hash_list(json_object *l, hash h) {
   return true;
 }
 
-bool object_hash(/*const*/ json_object *j, byte hash[HASH_SIZE]) {
+bool object_hash(/*const*/ json_object *j, byte hash[SHA256_DIGEST_LENGTH]) {
   enum json_type type;
   type = json_object_get_type(j);
   switch (type) {
