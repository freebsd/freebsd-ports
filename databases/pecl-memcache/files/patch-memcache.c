--- memcache.c.orig	2011-04-11 12:56:53.000000000 +0800
+++ memcache.c	2012-05-17 02:00:58.108724781 +0800
@@ -718,7 +718,7 @@
 			mmc_server_free(mmc TSRMLS_CC);
 			mmc = NULL;
 		} else {
-			zend_list_insert(mmc, le_memcache_server);
+			MEMCACHE_LIST_INSERT(mmc, le_memcache_server);
 		}
 	}
 	else if (le->type != le_memcache_server || le->ptr == NULL) {
@@ -735,7 +735,7 @@
 			mmc = NULL;
 		}
 		else {
-			zend_list_insert(mmc, le_memcache_server);
+			MEMCACHE_LIST_INSERT(mmc, le_memcache_server);
 		}
 	}
 	else {
@@ -775,7 +775,7 @@
 	if (zend_hash_find(Z_OBJPROP_P(mmc_object), "connection", sizeof("connection"), (void **)&connection) == FAILURE) {
 		pool = mmc_pool_new(TSRMLS_C);
 		pool->failure_callback = &php_mmc_failure_callback;
-		list_id = zend_list_insert(pool, le_memcache_pool);
+		list_id = MEMCACHE_LIST_INSERT(pool, le_memcache_pool);
 		add_property_resource(mmc_object, "connection", list_id);
 	}
 	else {
@@ -836,7 +836,7 @@
 		int list_id;
 		mmc_pool_t *pool = mmc_pool_new(TSRMLS_C);
 		pool->failure_callback = &php_mmc_failure_callback;
-		list_id = zend_list_insert(pool, le_memcache_pool);
+		list_id = MEMCACHE_LIST_INSERT(pool, le_memcache_pool);
 		mmc_object = return_value;
 		object_init_ex(mmc_object, memcache_ce);
 		add_property_resource(mmc_object, "connection", list_id);
@@ -986,7 +986,7 @@
 
 	/* check for userspace callback */
 	if (param != NULL && zend_hash_find(Z_OBJPROP_P((zval *)param), "_failureCallback", sizeof("_failureCallback"), (void **)&callback) == SUCCESS && Z_TYPE_PP(callback) != IS_NULL) {
-		if (IS_CALLABLE(*callback, 0, NULL)) {
+		if (MEMCACHE_IS_CALLABLE(*callback, 0, NULL)) {
 			zval *retval = NULL;
 			zval *host, *tcp_port, *udp_port, *error, *errnum;
 			zval **params[5];
@@ -1213,7 +1213,7 @@
 	}
 
 	if (failure_callback != NULL && Z_TYPE_P(failure_callback) != IS_NULL) {
-		if (!IS_CALLABLE(failure_callback, 0, NULL)) {
+		if (!MEMCACHE_IS_CALLABLE(failure_callback, 0, NULL)) {
 			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid failure callback");
 			RETURN_FALSE;
 		}
@@ -1275,7 +1275,7 @@
 	}
 
 	if (failure_callback != NULL && Z_TYPE_P(failure_callback) != IS_NULL) {
-		if (!IS_CALLABLE(failure_callback, 0, NULL)) {
+		if (!MEMCACHE_IS_CALLABLE(failure_callback, 0, NULL)) {
 			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid failure callback");
 			RETURN_FALSE;
 		}
@@ -1340,7 +1340,7 @@
 	}
 
 	if (Z_TYPE_P(failure_callback) != IS_NULL) {
-		if (!IS_CALLABLE(failure_callback, 0, NULL)) {
+		if (!MEMCACHE_IS_CALLABLE(failure_callback, 0, NULL)) {
 			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid failure callback");
 			RETURN_FALSE;
 		}
