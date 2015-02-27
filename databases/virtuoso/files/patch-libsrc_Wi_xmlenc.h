--- libsrc/Wi/xmlenc.h.orig	2014-02-17 18:33:14.000000000 +0100
+++ libsrc/Wi/xmlenc.h	2015-02-25 21:57:27.433398091 +0100
@@ -312,15 +312,15 @@
     } dsa;
     struct dsig_des3_keyinfo_s
     {
-      des_cblock k1;
-      des_cblock k2;
-      des_cblock k3;
-
-      des_key_schedule ks1;/* key schedule */
-      des_key_schedule ks2;/* key schedule (for ede) */
-      des_key_schedule ks3;/* key schedule (for ede3) */
+      DES_cblock k1;
+      DES_cblock k2;
+      DES_cblock k3;
+
+      DES_key_schedule ks1;/* key schedule */
+      DES_key_schedule ks2;/* key schedule (for ede) */
+      DES_key_schedule ks3;/* key schedule (for ede3) */
 
-      des_cblock iv;
+      DES_cblock iv;
 #define PKCS5_SALT_LEN			8
       unsigned char salt[PKCS5_SALT_LEN];
     } triple_des;
