--- src/protocol/dtls.cc.orig	2020-08-30 04:51:37 UTC
+++ src/protocol/dtls.cc
@@ -73,13 +73,17 @@ long BIO_ctrl(BIO *b, int cmd, long lval, void *ptrval
     case BIO_CTRL_DGRAM_GET_FALLBACK_MTU:
         retval = 1500;
         break;
+#ifdef BIO_CTRL_DGRAM_GET_MTU_OVERHEAD
     case BIO_CTRL_DGRAM_GET_MTU_OVERHEAD:
         retval = 96;  // random guess
         break;
+#endif
+#ifdef BIO_CTRL_DGRAM_SET_PEEK_MODE
     case BIO_CTRL_DGRAM_SET_PEEK_MODE:
         ((Session *) BIO_get_data(b))->peek_mode = !!lval;
         retval = 1;
         break;
+#endif
     case BIO_CTRL_PUSH:
     case BIO_CTRL_POP:
     case BIO_CTRL_DGRAM_SET_NEXT_TIMEOUT:
@@ -119,7 +123,7 @@ BIO_METHOD *BIO_get_methods(void) {
     BIO_meth_set_ctrl(_bio_methods, BIO_ctrl);
     BIO_meth_set_create(_bio_methods, BIO_create);
     BIO_meth_set_destroy(_bio_methods, BIO_destroy);
-    BIO_meth_set_callback_ctrl(_bio_methods, BIO_callback_ctrl);
+    BIO_meth_set_callback_ctrl(_bio_methods, (long (*)(BIO *, int, BIO_info_cb *)) BIO_callback_ctrl);
 
     return _bio_methods;
 }
