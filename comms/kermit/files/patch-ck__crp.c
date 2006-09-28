
$FreeBSD$

--- ck_crp.c.orig	Tue Jun 25 17:53:02 2002
+++ ck_crp.c	Tue Mar  4 15:14:45 2003
@@ -396,7 +396,7 @@
 des_new_random_key(Block B)
 {
     int rc=0;
-    rc = des_random_key(B);
+    des_random_key(B);
     return(rc);
 }
 
@@ -467,8 +467,8 @@
  * These function pointers point to the current routines
  * for encrypting and decrypting data.
  */
-static VOID     (*encrypt_output) P((unsigned char *, int));
-static int      (*decrypt_input) P((int));
+VOID     (*encrypt_output) P((unsigned char *, int));
+int      (*decrypt_input) P((int));
 
 #ifdef DEBUG
 static int encrypt_debug_mode = 1;
