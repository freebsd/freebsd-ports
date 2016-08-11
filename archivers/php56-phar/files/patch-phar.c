--- phar.c.orig	2016-06-22 01:50:40 UTC
+++ phar.c
@@ -3630,7 +3630,7 @@ static const zend_module_dep phar_deps[]
 	ZEND_MOD_OPTIONAL("openssl")
 	ZEND_MOD_OPTIONAL("zlib")
 	ZEND_MOD_OPTIONAL("standard")
-#if defined(HAVE_HASH) && !defined(COMPILE_DL_HASH)
+#if defined(HAVE_HASH)
 	ZEND_MOD_REQUIRED("hash")
 #endif
 #if HAVE_SPL
