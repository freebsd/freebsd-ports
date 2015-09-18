--- ext/openssl/ossl_rand.c.orig	2011-03-24 08:29:21.000000000 +0100
+++ ext/openssl/ossl_rand.c	2015-09-18 11:49:15.037631813 +0200
@@ -135,7 +135,10 @@ ossl_rand_egd(VALUE self, VALUE filename
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
