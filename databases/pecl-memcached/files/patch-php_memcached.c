Obtained from:	https://github.com/php-memcached-dev/php-memcached/commit/8bfdbcc9063dafcb25fdb1d1705e07ee027d7379

--- php_memcached.c.orig	2017-11-21 05:01:28 UTC
+++ php_memcached.c
@@ -1281,7 +1281,7 @@ static PHP_METHOD(Memcached, __construct
 		le.type = php_memc_list_entry();
 		le.ptr  = intern->memc;
 
-		GC_REFCOUNT(&le) = 1;
+		GC_SET_REFCOUNT(&le, 1);
 
 		/* plist_key is not a persistent allocated key, thus we use str_update here */
 		if (zend_hash_str_update_mem(&EG(persistent_list), ZSTR_VAL(plist_key), ZSTR_LEN(plist_key), &le, sizeof(le)) == NULL) {
@@ -3654,7 +3654,7 @@ PHP_METHOD(MemcachedServer, on)
 
 		Z_TRY_ADDREF(fci.function_name);
 		if (fci.object) {
-			GC_REFCOUNT(fci.object)++;
+			GC_ADDREF(fci.object);
 		}
 	}
 	RETURN_BOOL(rc);
