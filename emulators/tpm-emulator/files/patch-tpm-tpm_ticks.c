--- tpm/tpm_ticks.c.orig	2010-07-06 06:21:20.000000000 +0900
+++ tpm/tpm_ticks.c	2010-10-25 02:56:43.622559766 +0900
@@ -42,7 +42,7 @@
 {
   TPM_RESULT res;
   TPM_KEY_DATA *key;
-  BYTE *info, *ptr;
+  BYTE *info_buffer, *ptr;
   UINT32 info_length, len;
   info("TPM_TickStampBlob()");
   /* get key */
@@ -66,21 +66,21 @@
   if (*sig == NULL) return TPM_FAIL; 
   /* setup TPM_SIGN_INFO structure */
   info_length = 30 + sizeof(TPM_DIGEST) + sizeof_TPM_CURRENT_TICKS(currentTicks);
-  info = tpm_malloc(info_length);
-  if (info == NULL) {
+  info_buffer = tpm_malloc(info_length);
+  if (info_buffer == NULL) {
     tpm_free(*sig);
     return TPM_FAIL;
   }
-  memcpy(&info[0], "\x00\x05TSTP", 6);
-  memcpy(&info[6], antiReplay->nonce, 20);
-  ptr = &info[26]; len = info_length - 26;
+  memcpy(&info_buffer[0], "\x00\x05TSTP", 6);
+  memcpy(&info_buffer[6], antiReplay->nonce, 20);
+  ptr = &info_buffer[26]; len = info_length - 26;
   tpm_marshal_UINT32(&ptr, &len, info_length - 30);
   memcpy(ptr, digestToStamp->digest, sizeof(TPM_DIGEST));
   ptr += sizeof(TPM_DIGEST); len -= sizeof(TPM_DIGEST);
   if (tpm_marshal_TPM_CURRENT_TICKS(&ptr, &len, currentTicks)
-      || tpm_rsa_sign(&key->key, RSA_SSA_PKCS1_SHA1, info, info_length, *sig)) {
+      || tpm_rsa_sign(&key->key, RSA_SSA_PKCS1_SHA1, info_buffer, info_length, *sig)) {
     tpm_free(*sig);
-    tpm_free(info);
+    tpm_free(info_buffer);
     return TPM_FAIL;
   }
   return TPM_SUCCESS;
