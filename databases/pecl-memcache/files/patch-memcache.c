--- memcache.c.orig	Wed May  3 16:41:31 2006
+++ memcache.c	Wed May  3 16:42:05 2006
@@ -120,7 +120,7 @@
 
 /* {{{ macros */
 #define MMC_PREPARE_KEY(key, key_len) \
-	php_strtr(key, key_len, "\t\r\n ", "____", 4); \
+	php_strtr(key, key_len, "\t\r\n ", "____", 4);
 
 #if ZEND_DEBUG
 
