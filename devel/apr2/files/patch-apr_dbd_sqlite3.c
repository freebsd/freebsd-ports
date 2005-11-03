--- apr-util-1.2.2/dbd/apr_dbd_sqlite3.c.orig	Wed Nov  2 20:47:48 2005
+++ apr-util-1.2.2/dbd/apr_dbd_sqlite3.c	Wed Nov  2 20:55:50 2005
@@ -24,6 +24,7 @@
 #include <sqlite3.h>
 
 #include "apr_strings.h"
+#include "apr_thread_mutex.h"
 #include "apr_time.h"
 
 #include "apr_dbd_internal.h"
@@ -39,7 +40,9 @@
 struct apr_dbd_t {
     sqlite3 *conn;
     apr_dbd_transaction_t *trans;
+#if APR_HAS_THREADS
     apr_thread_mutex_t *mutex;
+#endif
     apr_pool_t *pool;
 };
 
@@ -92,11 +95,15 @@
         return sql->trans->errnum;
     }
 
+#if APR_HAS_THREADS
     apr_thread_mutex_lock(sql->mutex);
+#endif
 
     ret = sqlite3_prepare(sql->conn, query, strlen(query), &stmt, &tail);
     if (!dbd_sqlite3_is_success(ret)) {
+#if APR_HAS_THREADS
         apr_thread_mutex_unlock(sql->mutex);
+#endif
         return ret;
     } else {
         int column_count;
@@ -115,7 +122,9 @@
                 if (retry_count++ > MAX_RETRY_COUNT) {
                     ret = SQLITE_ERROR;
                 } else {
+#if APR_HAS_THREADS
                     apr_thread_mutex_unlock(sql->mutex);
+#endif
                     apr_sleep(MAX_RETRY_SLEEP);
                 }
             } else if (ret == SQLITE_ROW) {
@@ -170,7 +179,9 @@
         } while (ret == SQLITE_ROW || ret == SQLITE_BUSY);
     }
     ret = sqlite3_finalize(stmt);
+#if APR_HAS_THREADS
     apr_thread_mutex_unlock(sql->mutex);
+#endif
 
     if (sql->trans) {
         sql->trans->errnum = ret;
@@ -240,7 +251,9 @@
         return SQLITE_ERROR;
     }
     length = strlen(query);
+#if APR_HAS_THREADS
     apr_thread_mutex_lock(sql->mutex);
+#endif
 
     do {
         ret = sqlite3_prepare(sql->conn, query, length, &stmt, &tail);
@@ -259,7 +272,9 @@
     if (dbd_sqlite3_is_success(ret)) {
         res = 0;
     }
+#if APR_HAS_THREADS
     apr_thread_mutex_unlock(sql->mutex);
+#endif
     apr_pool_destroy(pool);
     if (sql->trans) {
         sql->trans->errnum = res;
@@ -366,12 +381,14 @@
     sql->conn = conn;
     sql->pool = pool;
     sql->trans = NULL;
+#if APR_HAS_THREADS
     /* Create a mutex */
     res = apr_thread_mutex_create(&sql->mutex, APR_THREAD_MUTEX_DEFAULT,
                                   pool);
     if (res != APR_SUCCESS) {
         return NULL;
     }
+#endif
 
     return sql;
 }
@@ -379,7 +396,9 @@
 static apr_status_t dbd_sqlite3_close(apr_dbd_t *handle)
 {
     sqlite3_close(handle->conn);
+#if APR_HAS_THREADS
     apr_thread_mutex_destroy(handle->mutex);
+#endif
     return APR_SUCCESS;
 }
 
