--- bdb.c.orig	2012-01-24 14:49:12.248201883 +0400
+++ bdb.c	2012-01-24 14:50:35.801194396 +0400
@@ -264,8 +264,6 @@
 }
 
 int bdb_create_queue(char *queue_name) {
-    pthread_rwlock_wrlock(&qlist_ht_lock);
-
     char *k = strdup(queue_name);
     assert(k != NULL);
     queue_t *q = (queue_t *)calloc(1, sizeof(queue_t));
@@ -309,14 +307,12 @@
     CHECK_DB_RET(ret);
     int result = hashtable_insert(qlist_htp, (void *)k, (void *)q);
     assert(result != 0);
-    pthread_rwlock_unlock(&qlist_ht_lock);
     return 0;
 dberr:
     if (txnp != NULL){
         txnp->abort(txnp);
     }
     fprintf(stderr, "bdb_create_queue: %s %s\n", queue_name, db_strerror(ret));
-    pthread_rwlock_unlock(&qlist_ht_lock);
     return -1;
 }
 
@@ -554,12 +550,13 @@
 
     if (NULL == q) {
         pthread_rwlock_unlock(&qlist_ht_lock);
+        /* switch to write lock */
+        pthread_rwlock_wrlock(&qlist_ht_lock);
         ret = bdb_create_queue(key);
         if (0 != ret){
             return -1;
         }
         /* search again */
-        pthread_rwlock_rdlock(&qlist_ht_lock);
         q = (queue_t *)hashtable_search(qlist_htp, (void *)key);        
     }
     
