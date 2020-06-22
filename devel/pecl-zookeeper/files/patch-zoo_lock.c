--- zoo_lock.c.orig	2019-12-11 01:31:04 UTC
+++ zoo_lock.c
@@ -97,11 +97,7 @@ ZOOAPI int zkr_lock_unlock(zkr_lock_mutex_t *mutex) {
         while (ret == ZCONNECTIONLOSS && (count < 3)) {
             ret = zoo_delete(zh, buf, -1);
             if (ret == ZCONNECTIONLOSS) {
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
                 LOG_DEBUG(LOGCALLBACK(zh), ("connectionloss while deleting the node"));
-#else
-                LOG_DEBUG(("connectionloss while deleting the node"));
-#endif
                 nanosleep(&ts, 0);
                 count++;
             }
@@ -117,11 +113,7 @@ ZOOAPI int zkr_lock_unlock(zkr_lock_mutex_t *mutex) {
             pthread_mutex_unlock(&(mutex->pmutex));
             return 0;
         }
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
         LOG_WARN(LOGCALLBACK(zh), ("not able to connect to server - giving up"));
-#else
-        LOG_WARN(("not able to connect to server - giving up"));
-#endif
         pthread_mutex_unlock(&(mutex->pmutex));
         return ZCONNECTIONLOSS;
     }
@@ -188,11 +180,7 @@ static int retry_getchildren(zhandle_t *zh, char* path
     while (ret == ZCONNECTIONLOSS && count < retry) {
         ret = zoo_get_children(zh, path, 0, vector);
         if (ret == ZCONNECTIONLOSS) {
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
             LOG_DEBUG(LOGCALLBACK(zh), ("connection loss to the server"));
-#else
-            LOG_DEBUG(("connection loss to the server"));
-#endif
             nanosleep(ts, 0);
             count++;
         }
@@ -228,11 +216,7 @@ static int retry_zoowexists(zhandle_t *zh, char* path,
     while (ret == ZCONNECTIONLOSS && count < retry) {
         ret = zoo_wexists(zh, path, watcher, ctx, stat);
         if (ret == ZCONNECTIONLOSS) {
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
             LOG_DEBUG(LOGCALLBACK(zh), ("connectionloss while setting watch on my predecessor"));
-#else
-            LOG_DEBUG(("connectionloss while setting watch on my predecessor"));
-#endif
             nanosleep(ts, 0);
             count++;
         }
@@ -287,11 +271,7 @@ static int zkr_lock_operation(zkr_lock_mutex_t *mutex,
             // do not want to retry the create since
             // we would end up creating more than one child
             if (ret != ZOK) {
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
                 LOG_WARN(LOGCALLBACK(zh), ("could not create zoo node %s", buf));
-#else
-                LOG_WARN(("could not create zoo node %s", buf));
-#endif
                 return ret;
             }
             mutex->id = getName(retbuf);
@@ -301,11 +281,7 @@ static int zkr_lock_operation(zkr_lock_mutex_t *mutex,
             ret = ZCONNECTIONLOSS;
             ret = retry_getchildren(zh, path, vector, ts, retry);
             if (ret != ZOK) {
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
                 LOG_WARN(LOGCALLBACK(zh), ("could not connect to server"));
-#else
-                LOG_WARN(("could not connect to server"));
-#endif
                 return ret;
             }
             //sort this list
@@ -327,11 +303,7 @@ static int zkr_lock_operation(zkr_lock_mutex_t *mutex,
                 // will keep waiting
                 if (ret != ZOK) {
                     free_String_vector(vector);
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
                     LOG_WARN(LOGCALLBACK(zh), ("unable to watch my predecessor"));
-#else
-                    LOG_WARN(("unable to watch my predecessor"));
-#endif
                     ret = zkr_lock_unlock(mutex);
                     while (ret == 0) {
                         //we have to give up our leadership
@@ -347,11 +319,7 @@ static int zkr_lock_operation(zkr_lock_mutex_t *mutex,
                 // this is the case when we are the owner
                 // of the lock
                 if (strcmp(mutex->id, owner_id) == 0) {
-#if ZOO_MAJOR_VERSION>=3 && ZOO_MINOR_VERSION>=5
                     LOG_DEBUG(LOGCALLBACK(zh), ("got the zoo lock owner - %s", mutex->id));
-#else
-                    LOG_DEBUG(("got the zoo lock owner - %s", mutex->id));
-#endif
                     mutex->isOwner = 1;
                     if (mutex->completion != NULL) {
                         mutex->completion(0, mutex->cbdata);
