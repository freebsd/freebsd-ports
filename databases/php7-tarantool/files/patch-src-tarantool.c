--- src/tarantool.c.orig	2018-04-18 13:33:56 UTC
+++ src/tarantool.c
@@ -1151,7 +1151,11 @@ PHP_METHOD(Tarantool, __construct) {
 		memset(&le, 0, sizeof(zend_resource));
 		le.type = php_tarantool_list_entry();
 		le.ptr  = obj;
+#if PHP_VERSION_ID >= 70300
+		GC_SET_REFCOUNT(&le, 1);
+#else
 		GC_REFCOUNT(&le) = 1;
+#endif
 
 		assert(plist_id != NULL);
 		if (zend_hash_update_mem(&EG(persistent_list), plist_id,
