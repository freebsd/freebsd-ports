--- openssl/hmac.cpp.orig	2013-02-12 08:59:05.000000000 +0100
+++ openssl/hmac.cpp	2013-02-12 09:00:43.000000000 +0100
@@ -17,12 +17,12 @@
 
 #include "local.h"
 
-bool HMAC::has(const char *id)
+bool ::HMAC::has(const char *id)
 {
     return (EVP_get_digestbyname(id) != NULL);
 }
 
-void HMAC::set(const char *digest, const char *key, size_t len)
+void ::HMAC::set(const char *digest, const char *key, size_t len)
 {
     secure::init();
 
@@ -39,7 +39,7 @@
     }
 }
 
-void HMAC::release(void)
+void ::HMAC::release(void)
 {
     if(context)
         HMAC_cleanup((HMAC_CTX *)context);
@@ -53,7 +53,7 @@
     textbuf[0] = 0;
 }
 
-bool HMAC::put(const void *address, size_t size)
+bool ::HMAC::put(const void *address, size_t size)
 {
     if(!context)
         return false;
@@ -62,7 +62,7 @@
     return true;
 }
 
-const unsigned char *HMAC::get(void)
+const unsigned char *::HMAC::get(void)
 {
     unsigned count = 0;
     unsigned size = 0;
