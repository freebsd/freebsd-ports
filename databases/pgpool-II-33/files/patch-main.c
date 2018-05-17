--- main.c.orig	2018-02-22 11:15:58 UTC
+++ main.c
@@ -360,7 +360,7 @@ int main(int argc, char **argv)
 
 #ifdef USE_SSL
     /* global ssl init */
-    #if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+    #if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
         OPENSSL_init_ssl(0, NULL);
     else
         SSL_library_init();
