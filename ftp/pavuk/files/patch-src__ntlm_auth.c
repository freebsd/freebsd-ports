--- src/ntlm_auth.c.orig	2005-10-27 16:06:37.000000000 +0200
+++ src/ntlm_auth.c	2015-02-28 12:38:57.150120721 +0100
@@ -249,14 +249,14 @@
 static void ntlm_des_enc(unsigned char *key, unsigned char *plaintext,
   unsigned char *result)
 {
-  des_key_schedule ks;
+  DES_key_schedule ks;
 #ifdef OPENSSL
-  const_des_cblock _plaintext;
+  const_DES_cblock _plaintext;
 #else
   const des_cblock _plaintext;
 #endif
-  des_cblock _result;
-  des_cblock key64;
+  DES_cblock _result;
+  DES_cblock key64;
   unsigned char skey[8];
 
   memcpy(&_plaintext, plaintext, sizeof(_plaintext));
@@ -265,10 +265,10 @@
   memcpy(key64, skey, 8);
 
 #ifdef OPENSSL
-  des_set_odd_parity(&key64);
-  des_set_key(&key64, ks);
+  DES_set_odd_parity(&key64);
+  DES_set_key(&key64, &ks);
 
-  des_ecb_encrypt(&_plaintext, &_result, ks, DES_ENCRYPT);
+  DES_ecb_encrypt(&_plaintext, &_result, &ks, DES_ENCRYPT);
 #else
   des_set_odd_parity(key64);
   des_set_key(key64, ks);
