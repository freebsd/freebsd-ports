Obtained from:	https://github.com/php-memcached-dev/php-memcached/commit/8bfdbcc9063dafcb25fdb1d1705e07ee027d7379

--- php_memcached_session.c.orig	2017-11-21 05:01:28 UTC
+++ php_memcached_session.c
@@ -376,7 +376,7 @@ PS_OPEN_FUNC(memcached)
 		le.type = s_memc_sess_list_entry();
 		le.ptr  = memc;
 
-		GC_REFCOUNT(&le) = 1;
+		GC_SET_REFCOUNT(&le, 1);
 
 		/* plist_key is not a persistent allocated key, thus we use str_update here */
 		if (zend_hash_str_update_mem(&EG(persistent_list), plist_key, plist_key_len, &le, sizeof(le)) == NULL) {
