--- src/hashtable.c.orig	2012-03-15 23:19:46.000000000 +0800
+++ src/hashtable.c	2012-03-15 23:21:20.000000000 +0800
@@ -118,10 +118,10 @@ static int hashtable_do_del(hashtable_t 
 {
     pair_t *pair;
     bucket_t *bucket;
-    size_t index;
+    size_t my_index;
 
-    index = hash % num_buckets(hashtable);
-    bucket = &hashtable->buckets[index];
+    my_index = hash % num_buckets(hashtable);
+    bucket = &hashtable->buckets[my_index];
 
     pair = hashtable_find_pair(hashtable, bucket, key, hash);
     if(!pair)
@@ -163,7 +163,7 @@ static int hashtable_do_rehash(hashtable
 {
     list_t *list, *next;
     pair_t *pair;
-    size_t i, index, new_size;
+    size_t i, my_index, new_size;
 
     jsonp_free(hashtable->buckets);
 
@@ -186,8 +186,8 @@ static int hashtable_do_rehash(hashtable
     for(; list != &hashtable->list; list = next) {
         next = list->next;
         pair = list_to_pair(list);
-        index = pair->hash % new_size;
-        insert_to_bucket(hashtable, &hashtable->buckets[index], &pair->list);
+        my_index = pair->hash % new_size;
+        insert_to_bucket(hashtable, &hashtable->buckets[my_index], &pair->list);
     }
 
     return 0;
@@ -227,7 +227,7 @@ int hashtable_set(hashtable_t *hashtable
 {
     pair_t *pair;
     bucket_t *bucket;
-    size_t hash, index;
+    size_t hash, my_index;
 
     /* rehash if the load ratio exceeds 1 */
     if(hashtable->size >= num_buckets(hashtable))
@@ -235,8 +235,8 @@ int hashtable_set(hashtable_t *hashtable
             return -1;
 
     hash = hash_str(key);
-    index = hash % num_buckets(hashtable);
-    bucket = &hashtable->buckets[index];
+    my_index = hash % num_buckets(hashtable);
+    bucket = &hashtable->buckets[my_index];
     pair = hashtable_find_pair(hashtable, bucket, key, hash);
 
     if(pair)
