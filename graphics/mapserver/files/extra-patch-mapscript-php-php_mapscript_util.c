--- mapscript/php/php_mapscript_util.c.orig	2012-09-05 14:32:18.000000000 +0800
+++ mapscript/php/php_mapscript_util.c	2012-09-05 14:35:09.000000000 +0800
@@ -42,7 +42,12 @@
     zobj->ce = ce;
     ALLOC_HASHTABLE(zobj->properties);
     zend_hash_init(zobj->properties, 0, NULL, ZVAL_PTR_DTOR, 0);
-    zend_hash_copy(zobj->properties, &ce->default_properties, (copy_ctor_func_t) zval_add_ref,(void *) &temp, sizeof(zval *));
+    //handle changes in PHP 5.4.x
+    #if PHP_VERSION_ID < 50399
+      zend_hash_copy(zobj->properties, &ce->default_properties, (copy_ctor_func_t) zval_add_ref,(void *) &temp, sizeof(zval *));
+    #else
+      object_properties_init(zobj, ce);
+    #endif
     retval.handle = zend_objects_store_put(zobj, NULL, (zend_objects_free_object_storage_t)zend_objects_free_object, NULL TSRMLS_CC);
     retval.handlers = &mapscript_std_object_handlers;
     return retval;
@@ -59,8 +64,12 @@
     zobj->ce = ce;
     ALLOC_HASHTABLE(zobj->properties);
     zend_hash_init(zobj->properties, 0, NULL, ZVAL_PTR_DTOR, 0);
-    zend_hash_copy(zobj->properties, &ce->default_properties, (copy_ctor_func_t) zval_add_ref,(void *) &temp, sizeof(zval *));
-    retval.handle = zend_objects_store_put(zobj, NULL, (zend_objects_free_object_storage_t)zend_objects_free_object, NULL TSRMLS_CC);
+    //handle changes in PHP 5.4.x
+    #if PHP_VERSION_ID < 50399
+      zend_hash_copy(zobj->properties, &ce->default_properties, (copy_ctor_func_t) zval_add_ref,(void *) &temp, sizeof(zval *));
+    #else
+      object_properties_init(zobj, ce);
+    #endif    retval.handle = zend_objects_store_put(zobj, NULL, (zend_objects_free_object_storage_t)zend_objects_free_object, NULL TSRMLS_CC);
     retval.handlers = object_handlers;
     return retval;
 }
