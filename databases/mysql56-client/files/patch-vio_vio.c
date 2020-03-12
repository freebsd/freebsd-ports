--- vio/vio.c.orig	2019-11-26 16:53:45 UTC
+++ vio/vio.c
@@ -394,7 +394,7 @@ void vio_end(void)
 {
 #if defined(HAVE_OPENSSL)
   // This one is needed on the client side
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   ERR_remove_thread_state(0);
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   ERR_free_strings();
