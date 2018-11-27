--- src/hashtable.c.orig	2018-02-08 09:05:40 UTC
+++ src/hashtable.c
@@ -108,10 +108,10 @@ static int hashtable_do_del(hashtable_t *hashtable,
 {
     pair_t *pair;
     bucket_t *bucket;
-    size_t index;
+    size_t idx;
 
-    index = hash & hashmask(hashtable->order);
-    bucket = &hashtable->buckets[index];
+    idx = hash & hashmask(hashtable->order);
+    bucket = &hashtable->buckets[idx];
 
     pair = hashtable_find_pair(hashtable, bucket, key, hash);
     if(!pair)
@@ -154,7 +154,7 @@ static int hashtable_do_rehash(hashtable_t *hashtable)
 {
     list_t *list, *next;
     pair_t *pair;
-    size_t i, index, new_size, new_order;
+    size_t i, idx, new_size, new_order;
     struct hashtable_bucket *new_buckets;
 
     new_order = hashtable->order + 1;
@@ -180,8 +180,8 @@ static int hashtable_do_rehash(hashtable_t *hashtable)
     for(; list != &hashtable->list; list = next) {
         next = list->next;
         pair = list_to_pair(list);
-        index = pair->hash % new_size;
-        insert_to_bucket(hashtable, &hashtable->buckets[index], &pair->list);
+        idx = pair->hash % new_size;
+        insert_to_bucket(hashtable, &hashtable->buckets[idx], &pair->list);
     }
 
     return 0;
@@ -220,7 +220,7 @@ int hashtable_set(hashtable_t *hashtable, const char *
 {
     pair_t *pair;
     bucket_t *bucket;
-    size_t hash, index;
+    size_t hash, idx;
 
     /* rehash if the load ratio exceeds 1 */
     if(hashtable->size >= hashsize(hashtable->order))
@@ -228,8 +228,8 @@ int hashtable_set(hashtable_t *hashtable, const char *
             return -1;
 
     hash = hash_str(key);
-    index = hash & hashmask(hashtable->order);
-    bucket = &hashtable->buckets[index];
+    idx = hash & hashmask(hashtable->order);
+    bucket = &hashtable->buckets[idx];
     pair = hashtable_find_pair(hashtable, bucket, key, hash);
 
     if(pair)
