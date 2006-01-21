--- ./memcache.c.orig	Wed Jan  4 23:33:18 2006
+++ ./memcache.c	Wed Jan  4 23:33:25 2006
@@ -120,7 +120,7 @@
 
 /* {{{ macros */
 #define MMC_PREPARE_KEY(key, key_len) \
-	php_strtr(key, key_len, "\t\r\n ", "____", 4); \
+	php_strtr(key, key_len, "\t\r\n ", "____", 4);
 
 #if ZEND_DEBUG
 
