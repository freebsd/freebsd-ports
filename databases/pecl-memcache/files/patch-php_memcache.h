--- php_memcache.h.orig	2012-05-17 02:01:32.293725097 +0800
+++ php_memcache.h	2012-05-17 02:03:47.294725872 +0800
@@ -72,9 +72,15 @@
 #define MMC_DEFAULT_CACHEDUMP_LIMIT	100		/* number of entries */
 
 #if (PHP_MAJOR_VERSION == 5) && (PHP_MINOR_VERSION >= 3)
-#   define IS_CALLABLE(cb_zv, flags, cb_sp) zend_is_callable((cb_zv), (flags), (cb_sp) TSRMLS_CC)
+#   define MEMCACHE_IS_CALLABLE(cb_zv, flags, cb_sp) zend_is_callable((cb_zv), (flags), (cb_sp) TSRMLS_CC)
 #else
-#   define IS_CALLABLE(cb_zv, flags, cb_sp) zend_is_callable((cb_zv), (flags), (cb_sp))
+#   define MEMCACHE_IS_CALLABLE(cb_zv, flags, cb_sp) zend_is_callable((cb_zv), (flags), (cb_sp))
+#endif
+
+#if (PHP_MAJOR_VERSION == 5) && (PHP_MINOR_VERSION >= 4)
+#    define MEMCACHE_LIST_INSERT(item, list) zend_list_insert(item, list TSRMLS_CC);
+#else
+#    define MEMCACHE_LIST_INSERT(item, list) zend_list_insert(item, list);
 #endif
 
 /* internal functions */
