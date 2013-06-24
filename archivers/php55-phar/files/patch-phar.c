--- phar.c.orig	2011-11-25 15:38:44.000000000 +0100
+++ phar.c	2011-11-25 15:39:01.000000000 +0100
@@ -3716,7 +3716,7 @@
 	ZEND_MOD_OPTIONAL("openssl")
 	ZEND_MOD_OPTIONAL("zlib")
 	ZEND_MOD_OPTIONAL("standard")
-#if defined(HAVE_HASH) && !defined(COMPILE_DL_HASH)
+#if defined(HAVE_HASH)
 	ZEND_MOD_REQUIRED("hash")
 #endif
 #if HAVE_SPL
