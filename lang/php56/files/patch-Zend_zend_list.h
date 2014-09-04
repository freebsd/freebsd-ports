--- Zend/zend_list.h.orig	2013-12-10 23:31:06.000000000 +0000
+++ Zend/zend_list.h	2013-12-13 21:50:25.087258407 +0000
@@ -71,9 +71,9 @@ int zend_init_rsrc_list_dtors(void);
 void zend_destroy_rsrc_list_dtors(void);
 
 ZEND_API int zend_list_insert(void *ptr, int type TSRMLS_DC);
-ZEND_API int _zend_list_addref(int id TSRMLS_DC);
-ZEND_API int _zend_list_delete(int id TSRMLS_DC);
-ZEND_API void *_zend_list_find(int id, int *type TSRMLS_DC);
+ZEND_API int _zend_list_addref(ulong id TSRMLS_DC);
+ZEND_API int _zend_list_delete(ulong id TSRMLS_DC);
+ZEND_API void *_zend_list_find(ulong id, int *type TSRMLS_DC);
 
 #define zend_list_addref(id)		_zend_list_addref(id TSRMLS_CC)
 #define zend_list_delete(id)		_zend_list_delete(id TSRMLS_CC)
@@ -82,7 +82,7 @@ ZEND_API void *_zend_list_find(int id, i
 ZEND_API int zend_register_resource(zval *rsrc_result, void *rsrc_pointer, int rsrc_type TSRMLS_DC);
 ZEND_API void *zend_fetch_resource(zval **passed_id TSRMLS_DC, int default_id, const char *resource_type_name, int *found_resource_type, int num_resource_types, ...);
 
-ZEND_API const char *zend_rsrc_list_get_rsrc_type(int resource TSRMLS_DC);
+ZEND_API const char *zend_rsrc_list_get_rsrc_type(ulong resource TSRMLS_DC);
 ZEND_API int zend_fetch_list_dtor_id(char *type_name);
 
 extern ZEND_API int le_index_ptr;  /* list entry type for index pointers */
