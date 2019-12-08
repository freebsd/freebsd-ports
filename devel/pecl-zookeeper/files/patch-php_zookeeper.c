--- php_zookeeper.c.orig	2019-03-08 00:37:59 UTC
+++ php_zookeeper.c
@@ -1068,7 +1068,7 @@ static void php_parse_acl_list(zval *z_a
 {
 	int size = 0;
 	int i = 0;
-	ulong index = 0;
+	zend_ulong index = 0;
 	zend_string *key;
 	zval *entry = NULL;
 	zval *perms = NULL;
