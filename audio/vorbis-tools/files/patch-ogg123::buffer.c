
$FreeBSD$

--- ogg123/buffer.c.orig	Thu Dec 20 01:24:53 2001
+++ ogg123/buffer.c	Sat Jan 19 16:24:44 2002
@@ -85,12 +85,6 @@
   buf_t *buf = (buf_t *)arg;
 
   DEBUG("Enter buffer_thread_cleanup");
-
-  /* Cleanup thread data structures */
-  pthread_mutex_unlock(&buf->mutex);
-  pthread_mutex_destroy(&buf->mutex);
-  pthread_cond_destroy(&buf->playback_cond);
-  pthread_cond_destroy(&buf->write_cond);
 }
 
 
@@ -430,6 +424,12 @@
 void buffer_destroy (buf_t *buf)
 {
   DEBUG("buffer_destroy");
+
+  /* Cleanup pthread variables */
+  pthread_mutex_destroy(&buf->mutex);
+  pthread_cond_destroy(&buf->write_cond);
+  pthread_cond_destroy(&buf->playback_cond);
+  
   free(buf);
 }
 
