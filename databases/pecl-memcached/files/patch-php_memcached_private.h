Obtained from:	https://github.com/php-memcached-dev/php-memcached/commit/8bfdbcc9063dafcb25fdb1d1705e07ee027d7379

--- php_memcached_private.h.orig	2017-11-21 05:01:28 UTC
+++ php_memcached_private.h
@@ -72,6 +72,13 @@ typedef unsigned long int uint32_t;
 #  endif
 #endif
 
+/* Backwards compatibility for GC API change in PHP 7.3 */
+#if PHP_VERSION_ID < 70300
+#  define GC_ADDREF(p)            ++GC_REFCOUNT(p)
+#  define GC_DELREF(p)            --GC_REFCOUNT(p)
+#  define GC_SET_REFCOUNT(p, rc)  GC_REFCOUNT(p) = rc
+#endif
+
 /****************************************
   Structures and definitions
 ****************************************/
