--- php_zookeeper.c.orig	2012-01-14 06:08:49.000000000 +0800
+++ php_zookeeper.c	2013-01-12 16:24:08.000000000 +0800
@@ -715,7 +715,11 @@
 
     i_obj = ecalloc(1, sizeof(*i_obj));
 	zend_object_std_init( &i_obj->zo, ce TSRMLS_CC );
+#if PHP_VERSION_ID < 50399
     zend_hash_copy(i_obj->zo.properties, &ce->default_properties, (copy_ctor_func_t) zval_add_ref, (void *) &tmp, sizeof(zval *));
+#else
+	object_properties_init(&(i_obj->zo), ce);
+#endif
 
     retval.handle = zend_objects_store_put(i_obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, (zend_objects_free_object_storage_t)php_zk_free_storage, NULL TSRMLS_CC);
     retval.handlers = zend_get_std_object_handlers();
