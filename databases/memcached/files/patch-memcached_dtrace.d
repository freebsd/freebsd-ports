--- memcached_dtrace.d.orig	2017-08-27 18:22:57 UTC
+++ memcached_dtrace.d
@@ -111,19 +111,15 @@ provider memcached {
     * Fired when a new item has been inserted.
     * @param key the key just inserted
     * @param keylen length of the key
-    * @param nokeys the total number of keys currently stored,
-    *               including the key for which insert was called.
     */
-   probe assoc__insert(const char *key, int keylen, int nokeys);
+   probe assoc__insert(const char *key, int keylen);
 
    /**
     * Fired when a new item has been removed.
     * @param key the key just deleted
     * @param keylen length of the key
-    * @param nokeys the total number of keys currently stored,
-    *               excluding the key for which delete was called.
     */
-   probe assoc__delete(const char *key, int keylen, int nokeys);
+   probe assoc__delete(const char *key, int keylen);
 
    /**
     * Fired when an item is linked into the cache.
