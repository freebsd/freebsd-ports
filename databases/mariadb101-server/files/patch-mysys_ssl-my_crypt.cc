--- mysys_ssl/my_crypt.cc.orig	2016-08-29 16:38:54.000000000 +0200
+++ mysys_ssl/my_crypt.cc	2016-10-17 19:14:45.146531847 +0200
@@ -275,10 +275,14 @@
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
@@ -288,6 +292,7 @@
   RAND_METHOD *rand = RAND_SSLeay();
   if (rand == NULL || rand->bytes(buf, num) != 1)
     return MY_AES_OPENSSL_ERROR;
+#endif
   return MY_AES_OK;
 }
 #endif
