--- phar.c.orig	2016-06-21 11:11:59 UTC
+++ phar.c
@@ -3651,7 +3651,7 @@ static const zend_module_dep phar_deps[]
 	ZEND_MOD_OPTIONAL("openssl")
 	ZEND_MOD_OPTIONAL("zlib")
 	ZEND_MOD_OPTIONAL("standard")
-#if defined(HAVE_HASH) && !defined(COMPILE_DL_HASH)
+#if defined(HAVE_HASH)
 	ZEND_MOD_REQUIRED("hash")
 #endif
 #if HAVE_SPL
