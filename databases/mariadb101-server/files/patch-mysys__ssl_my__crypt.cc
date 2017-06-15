--- mysys_ssl/my_crypt.cc.orig	2017-01-17 19:38:25 UTC
+++ mysys_ssl/my_crypt.cc
@@ -275,10 +275,14 @@ int my_random_bytes(uchar* buf, int num)
   return MY_AES_OK;
 }
 #else
+#include <openssl/opensslv.h>
 #include <openssl/rand.h>
 
 int my_random_bytes(uchar *buf, int num)
 {
+#if defined(LIBRESSL_VERSION_NUMBER)
+  arc4random_buf(buf, num);
+#else
   /*
     Unfortunately RAND_bytes manual page does not provide any guarantees
     in relation to blocking behavior. Here we explicitly use SSLeay random
@@ -288,6 +292,7 @@ int my_random_bytes(uchar *buf, int num)
   RAND_METHOD *rand = RAND_SSLeay();
   if (rand == NULL || rand->bytes(buf, num) != 1)
     return MY_AES_OPENSSL_ERROR;
+#endif
   return MY_AES_OK;
 }
 #endif
