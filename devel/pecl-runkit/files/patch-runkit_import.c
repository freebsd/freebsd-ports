--- ./runkit_import.c.orig	2006-06-06 17:06:08.000000000 -0400
+++ ./runkit_import.c	2010-04-13 00:04:47.000000000 -0400
@@ -226,7 +226,9 @@
 		if (zend_hash_get_current_key_ex(&ce->default_properties, &key, &key_len, &idx, 0, &pos) == HASH_KEY_IS_STRING) {
 			char *cname = NULL, *pname = key;
 
-#ifdef ZEND_ENGINE_2
+#ifdef ZEND_ENGINE_2_2
+			zend_unmangle_property_name(key, key_len - 1, &cname, &pname);
+#elif defined(ZEND_ENGINE_2)
 			zend_unmangle_property_name(key, &cname, &pname);
 #endif
 			if (zend_hash_exists(&dce->default_properties, key, key_len)) {
