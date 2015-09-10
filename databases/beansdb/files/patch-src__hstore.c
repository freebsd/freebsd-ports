--- src/hstore.c.orig	2013-07-17 08:09:12 UTC
+++ src/hstore.c
@@ -45,14 +45,14 @@ struct t_hstore {
     Bitcask* bitcasks[];
 };
 
-inline int get_index(HStore *store, char *key)
+static inline int get_index(HStore *store, char *key)
 {
     if (store->height == 0) return 0;
     uint32_t h = fnv1a(key, strlen(key));
     return h >> ((8 - store->height) * 4);
 }
 
-inline pthread_mutex_t* get_mutex(HStore *store, char *key)
+static inline pthread_mutex_t* get_mutex(HStore *store, char *key)
 {
     uint32_t i = fnv1a(key, strlen(key)) % NUM_OF_MUTEX;
     return &store->locks[i];
