--- ext/openssl/ossl_rand.c.orig	2014-10-04 02:01:07.000000000 +0200
+++ ext/openssl/ossl_rand.c	2015-09-18 10:28:23.817969432 +0200
@@ -159,7 +159,10 @@ ossl_rand_egd(VALUE self, VALUE filename
 {
     SafeStringValue(filename);
 
-    if(!RAND_egd(RSTRING_PTR(filename))) {
+#ifndef OPENSSL_NO_EGD
+    if(!RAND_egd(RSTRING_PTR(filename)))
+#endif
+    {
 	ossl_raise(eRandomError, NULL);
     }
     return Qtrue;
