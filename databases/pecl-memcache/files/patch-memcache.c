--- memcache.c.orig	Wed May  3 16:41:31 2006
+++ memcache.c	Wed May  3 16:42:05 2006
@@ -120,7 +120,7 @@
 
 /* {{{ macros */
 #define MMC_PREPARE_KEY(key, key_len) \
-	php_strtr(key, key_len, "\t\r\n ", "____", 4); \
+	php_strtr(key, key_len, "\t\r\n ", "____", 4);
 
 #if ZEND_DEBUG
 
@@ -580,7 +580,9 @@
 				if ((version = mmc_get_version(mmc TSRMLS_CC)) == NULL && !_mmc_open(mmc, error_string, errnum TSRMLS_CC)) {
 					break;
 				}
-				efree(version);
+				if (version) {
+					efree(version);
+				}
 				mmc->status = MMC_STATUS_CONNECTED;
 			}
 			return 1;
