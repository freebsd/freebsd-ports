Obtained from:	https://github.com/php-memcached-dev/php-memcached/commit/c94e014da53cc8a3d0510402f36bc6e5e17bf608

--- php_memcached_server.c.orig	2019-12-03 22:13:53 UTC
+++ php_memcached_server.c
@@ -63,7 +63,9 @@ long s_invoke_php_callback (php_memc_server_cb_t *cb, 
 	cb->fci.retval = retval;
 	cb->fci.params = params;
 	cb->fci.param_count = param_count;
+#if PHP_VERSION_ID < 80000
 	cb->fci.no_separation = 1;
+#endif
 
 	if (zend_call_function(&(cb->fci), &(cb->fci_cache)) == FAILURE) {
 		char *buf = php_memc_printable_func(&(cb->fci), &(cb->fci_cache));
