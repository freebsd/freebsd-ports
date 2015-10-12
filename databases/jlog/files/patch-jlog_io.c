--- jlog_io.c.orig	2015-08-14 14:37:55.150718000 -0700
+++ jlog_io.c	2015-08-14 14:38:46.803672000 -0700
@@ -129,6 +129,7 @@
     assert(jlog_hash_delete(&jlog_files, (void *)&f->id, sizeof(jlog_file_id),
                             NULL, NULL));
     while (close(f->fd) == -1 && errno == EINTR) ;
+    pthread_mutex_destroy(&(f->lock));
     free(f);
   }
   pthread_mutex_unlock(&jlog_files_lock);  
