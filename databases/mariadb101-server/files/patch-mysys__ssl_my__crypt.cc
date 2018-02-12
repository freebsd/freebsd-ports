--- mysys_ssl/my_crypt.cc.orig	2018-02-04 02:30:31 UTC
+++ mysys_ssl/my_crypt.cc
@@ -27,6 +27,7 @@
 #include <openssl/aes.h>
 #include <openssl/err.h>
 #include <openssl/rand.h>
+#include <openssl/opensslv.h>
 
 #ifdef HAVE_ERR_remove_thread_state
 #define ERR_remove_state(X) ERR_remove_thread_state(NULL)
@@ -295,6 +296,9 @@ unsigned int my_aes_ctx_size(enum my_aes
 
 int my_random_bytes(uchar *buf, int num)
 {
+#ifdef LIBRESSL_VERSION_NUMBER
+  arc4random_buf(buf, num);
+#endif
   if (RAND_bytes(buf, num) != 1)
     return MY_AES_OPENSSL_ERROR;
   return MY_AES_OK;
