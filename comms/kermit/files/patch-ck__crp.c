
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
 
