--- php_drizzle.c.orig	1970-01-01 17:13:08.000000000 +0800
+++ php_drizzle.c	2015-11-30 22:02:21.309689000 +0800
@@ -1314,9 +1314,13 @@
 	}
 
 	zend_object_std_init(&(obj->std), class_type TSRMLS_CC);
+#if PHP_VERSION_ID < 50399
 	zend_hash_copy(obj->std.properties, &(class_type->default_properties),
 	              (copy_ctor_func_t)zval_add_ref, (void *)(&tmp),
 	               sizeof(zval *));
+#else
+	object_properties_init((zend_object*) &(obj->std), class_type);
+#endif
 
 	value.handle= zend_objects_store_put(obj,
 	                   (zend_objects_store_dtor_t)zend_objects_destroy_object,
@@ -1582,9 +1586,13 @@
 	}
 
 	zend_object_std_init(&(obj->std), class_type TSRMLS_CC);
+#if PHP_VERSION_ID < 50399
 	zend_hash_copy(obj->std.properties, &(class_type->default_properties),
 	               (copy_ctor_func_t)zval_add_ref, (void *)(&tmp),
 	               sizeof(zval *));
+#else
+	object_properties_init((zend_object*) &(obj->std), class_type);
+#endif
 
 	obj->value.handle= zend_objects_store_put(obj,
 	                  (zend_objects_store_dtor_t)zend_objects_destroy_object,
@@ -2505,9 +2513,13 @@
 	}
 
 	zend_object_std_init(&(obj->std), class_type TSRMLS_CC);
+#if PHP_VERSION_ID < 50399
 	zend_hash_copy(obj->std.properties, &(class_type->default_properties),
 	               (copy_ctor_func_t)zval_add_ref, (void *)(&tmp),
 	               sizeof(zval *));
+#else
+	object_properties_init((zend_object*) &(obj->std), class_type);
+#endif
 
 	obj->value.handle= zend_objects_store_put(obj,
 	               (zend_objects_store_dtor_t)zend_objects_destroy_object,
@@ -3017,9 +3029,13 @@
 	}
 
 	zend_object_std_init(&(result->std), class_type TSRMLS_CC);
+#if PHP_VERSION_ID < 50399
 	zend_hash_copy(result->std.properties, &(class_type->default_properties),
 	               (copy_ctor_func_t)zval_add_ref, (void *)(&tmp),
 	               sizeof(zval *));
+#else
+	object_properties_init((zend_object*) &(result->std), class_type);
+#endif
 
 	value.handle= zend_objects_store_put(result,
 	              (zend_objects_store_dtor_t)zend_objects_destroy_object,
@@ -3382,9 +3398,13 @@
 	}
 
 	zend_object_std_init(&(obj->std), class_type TSRMLS_CC);
+#if PHP_VERSION_ID < 50399
 	zend_hash_copy(obj->std.properties, &(class_type->default_properties),
 	               (copy_ctor_func_t)zval_add_ref, (void *)(&tmp),
 	               sizeof(zval *));
+#else
+	object_properties_init((zend_object*) &(obj->std), class_type);
+#endif
 
 	value.handle= zend_objects_store_put(obj,
 	             (zend_objects_store_dtor_t)zend_objects_destroy_object,
