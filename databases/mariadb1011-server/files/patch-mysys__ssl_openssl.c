--- mysys_ssl/openssl.c.orig	2024-02-01 17:44:37 UTC
+++ mysys_ssl/openssl.c
@@ -30,6 +30,11 @@ int check_openssl_compatibility()
 {
   return 0;
 }
+#elif defined(LIBRESSL_VERSION_NUMBER)
+int check_openssl_compatibility()
+{
+  return 0;
+}
 #else
 #include <openssl/evp.h>
 
