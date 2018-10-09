--- php7_wrapper.h.orig	2018-10-09 11:57:28 UTC
+++ php7_wrapper.h
@@ -456,7 +456,11 @@ static inline int sw_zend_register_class
 
     zend_string *_interned_name = zend_new_interned_string(_name);
 
+#if PHP_VERSION_ID >= 70300
+    return zend_register_class_alias_ex(_interned_name->val, _interned_name->len, ce, 1);
+#else
     return zend_register_class_alias_ex(_interned_name->val, _interned_name->len, ce);
+#endif
 }
 
 static inline char* sw_http_build_query(zval *data, zend_size_t *length, smart_str *formstr TSRMLS_DC)
