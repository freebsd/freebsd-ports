Obtained from:	https://github.com/websupport-sk/pecl-memcache/commit/09e21a63410cbfd8827c7a876d8160a6b80b076c

--- php7/memcache_pool.c.orig	2019-03-04 21:49:48 UTC
+++ php7/memcache_pool.c
@@ -44,6 +44,9 @@ ZEND_DECLARE_MODULE_GLOBALS(memcache)
 MMC_POOL_INLINE void mmc_buffer_alloc(mmc_buffer_t *buffer, unsigned int size)  /*
 	ensures space for an additional size bytes {{{ */
 {
+#if PHP_VERSION_ID < 70200
+	register size_t newlen;
+#endif
 	smart_string_alloc((&(buffer->value)), size, 0);
 }
 /* }}} */
