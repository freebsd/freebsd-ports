--- Zend/zend_list.c.orig	2012-01-01 14:15:04.000000000 +0100
+++ Zend/zend_list.c	2012-03-02 10:29:02.000000000 +0100
@@ -47,7 +47,7 @@
 	return index;
 }
 
-ZEND_API int _zend_list_delete(int id TSRMLS_DC)
+ZEND_API int _zend_list_delete(ulong id TSRMLS_DC)
 {
 	zend_rsrc_list_entry *le;
 	
@@ -64,7 +64,7 @@
 }
 
 
-ZEND_API void *_zend_list_find(int id, int *type TSRMLS_DC)
+ZEND_API void *_zend_list_find(ulong id, int *type TSRMLS_DC)
 {
 	zend_rsrc_list_entry *le;
 
@@ -77,7 +77,7 @@
 	}
 }
 
-ZEND_API int _zend_list_addref(int id TSRMLS_DC)
+ZEND_API int _zend_list_addref(ulong id TSRMLS_DC)
 {
 	zend_rsrc_list_entry *le;
 	
@@ -348,7 +348,7 @@
 }
 
 
-const char *zend_rsrc_list_get_rsrc_type(int resource TSRMLS_DC)
+const char *zend_rsrc_list_get_rsrc_type(ulong resource TSRMLS_DC)
 {
 	zend_rsrc_list_dtors_entry *lde;
 	int rsrc_type;
