--- src/hashtable.c.orig	2014-02-11 15:53:06.000000000 +0800
+++ src/hashtable.c	2014-02-15 18:45:56.864995487 +0800
@@ -103,10 +103,10 @@ static int hashtable_do_del(hashtable_t 
 {
     pair_t *pair;
     bucket_t *bucket;
-    size_t index;
+    size_t ind;
 
-    index = hash & hashmask(hashtable->order);
-    bucket = &hashtable->buckets[index];
+    ind = hash & hashmask(hashtable->order);
+    bucket = &hashtable->buckets[ind];
 
     pair = hashtable_find_pair(hashtable, bucket, key, hash);
     if(!pair)
@@ -148,7 +148,7 @@ static int hashtable_do_rehash(hashtable
 {
     list_t *list, *next;
     pair_t *pair;
-    size_t i, index, new_size;
+    size_t i, ind, new_size;
 
     jsonp_free(hashtable->buckets);
 
@@ -171,8 +171,8 @@ static int hashtable_do_rehash(hashtable
     for(; list != &hashtable->list; list = next) {
         next = list->next;
         pair = list_to_pair(list);
-        index = pair->hash % new_size;
-        insert_to_bucket(hashtable, &hashtable->buckets[index], &pair->list);
+        ind = pair->hash % new_size;
+        insert_to_bucket(hashtable, &hashtable->buckets[ind], &pair->list);
     }
 
     return 0;
@@ -212,7 +212,7 @@ int hashtable_set(hashtable_t *hashtable
 {
     pair_t *pair;
     bucket_t *bucket;
-    size_t hash, index;
+    size_t hash, ind;
 
     /* rehash if the load ratio exceeds 1 */
     if(hashtable->size >= hashsize(hashtable->order))
@@ -220,8 +220,8 @@ int hashtable_set(hashtable_t *hashtable
             return -1;
 
     hash = hash_str(key);
-    index = hash & hashmask(hashtable->order);
-    bucket = &hashtable->buckets[index];
+    ind = hash & hashmask(hashtable->order);
+    bucket = &hashtable->buckets[ind];
     pair = hashtable_find_pair(hashtable, bucket, key, hash);
 
     if(pair)
