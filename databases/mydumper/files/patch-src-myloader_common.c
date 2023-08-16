--- src/mydumper_common.c.orig	2023-08-02 14:40:15 UTC
+++ src/mydumper_common.c
@@ -123,7 +123,7 @@ int m_close_pipe(guint thread_id, void *file, gchar *f
   g_mutex_lock(fifo_table_mutex);
   struct fifo *f=g_hash_table_lookup(fifo_hash,file);
   g_mutex_unlock(fifo_table_mutex);
-  int r=close(fileno(file));
+  int r=close(fileno((FILE *) file));
   if (f != NULL){
     int status=0;
     waitpid(f->pid, &status, 0);
