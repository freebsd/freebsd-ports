--- gol.c.orig	2014-05-20 03:11:04.000000000 +0200
+++ gol.c	2015-02-28 20:05:59.171972929 +0100
@@ -1427,18 +1427,18 @@
             r-(ptr-top)-6, &aeskey, (unsigned char*) iv, AES_DECRYPT);
       }
       else if (!strcmp(crypt_algorythm, "DES")) {
-        des_key_schedule schedule;
+        DES_key_schedule schedule;
         DES_set_key_unchecked((const_DES_cblock*) &digest, &schedule);
         DES_ncbc_encrypt((unsigned char*) ptr, (unsigned char*) data,
             r-(ptr-top)-6, &schedule, (const_DES_cblock*) &iv, DES_DECRYPT);
       }
       else if (!strcmp(crypt_algorythm, "3DES")) {
-        des_key_schedule schedule1, schedule2, schedule3;
+        DES_key_schedule schedule1, schedule2, schedule3;
         DES_set_key_unchecked((const_DES_cblock*) (digest+ 0), &schedule1);
         DES_set_key_unchecked((const_DES_cblock*) (digest+ 8), &schedule2);
         DES_set_key_unchecked((const_DES_cblock*) (digest+16), &schedule3);
-        des_ede3_cbc_encrypt((unsigned char*) ptr, (unsigned char*) data,
-            r-(ptr-top)-6, schedule1, schedule2, schedule3,
+        DES_ede3_cbc_encrypt((unsigned char*) ptr, (unsigned char*) data,
+            r-(ptr-top)-6, &schedule1, &schedule2, &schedule3,
             (const_DES_cblock*) &iv, DES_DECRYPT);
       } else {
         data = strdup(ptr);
