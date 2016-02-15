--- phar.c.orig	2015-12-10 14:18:59.933565343 +0300
+++ phar.c	2015-12-10 14:19:28.787563292 +0300
@@ -3578,7 +3578,7 @@
 	ZEND_MOD_OPTIONAL("openssl")
 	ZEND_MOD_OPTIONAL("zlib")
 	ZEND_MOD_OPTIONAL("standard")
-#if defined(HAVE_HASH) && !defined(COMPILE_DL_HASH)
+#if defined(HAVE_HASH)
 	ZEND_MOD_REQUIRED("hash")
 #endif
 #if HAVE_SPL
