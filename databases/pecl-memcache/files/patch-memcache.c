--- memcache.c.orig	2007-10-28 22:53:21.000000000 +0100
+++ memcache.c	2007-10-28 22:53:54.000000000 +0100
@@ -201,7 +201,7 @@
 
 /* {{{ macros */
 #define MMC_PREPARE_KEY(key, key_len) \
-	php_strtr(key, key_len, "\t\r\n ", "____", 4); \
+	php_strtr(key, key_len, "\t\r\n ", "____", 4);
 /* }}} */
 
 /* {{{ internal function protos */
