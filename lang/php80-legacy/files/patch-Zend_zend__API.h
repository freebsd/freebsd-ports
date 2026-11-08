--- Zend/zend_API.h.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_API.h
@@ -428,6 +428,7 @@ ZEND_API const char *zend_get_type_by_const(int type);
 
 #define array_init(arg)				ZVAL_ARR((arg), zend_new_array(0))
 #define array_init_size(arg, size)	ZVAL_ARR((arg), zend_new_array(size))
+#define array_init_singleton(arg)	ZVAL_ARR((arg), zend_new_array_singleton())
 ZEND_API void object_init(zval *arg);
 ZEND_API zend_result object_init_ex(zval *arg, zend_class_entry *ce);
 ZEND_API zend_result object_and_properties_init(zval *arg, zend_class_entry *ce, HashTable *properties);
