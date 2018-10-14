--- php7/memcache.c.orig	2017-08-02 09:38:18 UTC
+++ php7/memcache.c
@@ -728,7 +728,11 @@ mmc_t *mmc_find_persistent(const char *h
 		mmc = mmc_server_new(host, host_len, port, udp_port, 1, timeout, retry_interval);
 		le->type = le_memcache_server;
 		le->ptr  = mmc;
+#if PHP_VERSION_ID >= 70300
+		GC_SET_REFCOUNT(le, 1);
+#else
 		GC_REFCOUNT(le) = 1;
+#endif
 
 		/* register new persistent connection */
 		if (zend_hash_str_update_mem(&EG(persistent_list), key, key_len, le, sizeof(*le)) == NULL) {
@@ -786,7 +790,11 @@ static mmc_t *php_mmc_pool_addserver(
 		pool->failure_callback = &php_mmc_failure_callback;
 		list_res = zend_register_resource(pool, le_memcache_pool);
 		add_property_resource(mmc_object, "connection", list_res);
+#if PHP_VERSION_ID >= 70300
+		GC_ADDREF(list_res);
+#else
 		GC_REFCOUNT(list_res)++;
+#endif
 	}
 	else {
 		pool = zend_fetch_resource_ex(connection, "connection", le_memcache_pool);
@@ -870,7 +878,11 @@ static void php_mmc_connect(INTERNAL_FUN
 		mmc_object = return_value;
 		object_init_ex(mmc_object, memcache_ce);
 		add_property_resource(mmc_object, "connection", list_res);
+#if PHP_VERSION_ID >= 70300
+		GC_ADDREF(list_res);
+#else
 		GC_REFCOUNT(list_res)++;
+#endif
 	} else {
 		RETVAL_TRUE;
 	}
