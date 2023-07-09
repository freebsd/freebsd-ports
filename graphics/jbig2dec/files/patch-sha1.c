--- sha1.c.orig	2020-09-10 15:14:14 UTC
+++ sha1.c
@@ -86,6 +86,13 @@ A million repetitions of "a"
 #include <string.h>
 
 #include "os_types.h"
+
+#include <sha.h>
+#ifndef SHA1_DIGEST_SIZE
+#define SHA1_DIGEST_SIZE 20
+#endif
+
+#if 0
 #include "sha1.h"
 
 void SHA1_Transform(uint32_t state[5], const uint8_t buffer[64]);
@@ -225,7 +232,7 @@ SHA1_Update(SHA1_CTX *context, const uint8_t *data, co
 
 /* Add padding and return the message digest. */
 void
-SHA1_Final(SHA1_CTX *context, uint8_t digest[SHA1_DIGEST_SIZE])
+SHA1_Final(uint8_t digest[SHA1_DIGEST_SIZE], SHA1_CTX *context)
 {
     uint32_t i;
     uint8_t finalcount[8];
@@ -258,7 +265,6 @@ SHA1_Final(SHA1_CTX *context, uint8_t digest[SHA1_DIGE
 
 /*************************************************************/
 
-#if 0
 int
 main(int argc, char **argv)
 {
@@ -286,7 +292,7 @@ main(int argc, char **argv)
         i = fread(buffer, 1, 16384, file);
         SHA1_Update(&context, buffer, i);
     }
-    SHA1_Final(&context, digest);
+    SHA1_Final(digest, &context);
     fclose(file);
     for (i = 0; i < SHA1_DIGEST_SIZE / 4; i++) {
         for (j = 0; j < 4; j++) {
@@ -344,7 +350,7 @@ main(int argc, char **argv)
     for (k = 0; k < 2; k++) {
         SHA1_Init(&context);
         SHA1_Update(&context, (uint8_t *) test_data[k], strlen(test_data[k]));
-        SHA1_Final(&context, digest);
+        SHA1_Final(digest, &context);
         digest_to_hex(digest, output);
 
         if (strcmp(output, test_results[k])) {
@@ -359,7 +365,7 @@ main(int argc, char **argv)
     SHA1_Init(&context);
     for (k = 0; k < 1000000; k++)
         SHA1_Update(&context, (uint8_t *) "a", 1);
-    SHA1_Final(&context, digest);
+    SHA1_Final(digest, &context);
     digest_to_hex(digest, output);
     if (strcmp(output, test_results[2])) {
         fprintf(stdout, "FAIL\n");
