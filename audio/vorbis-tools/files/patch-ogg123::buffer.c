
$FreeBSD$

--- ogg123/buffer.c.orig	Thu Dec 20 01:24:53 2001
+++ ogg123/buffer.c	Wed Jan 16 03:26:15 2002
@@ -88,9 +88,11 @@
 
   /* Cleanup thread data structures */
   pthread_mutex_unlock(&buf->mutex);
+#if 0	/* KLUDGE: disabling this keeps ogg123 from crashing */
   pthread_mutex_destroy(&buf->mutex);
   pthread_cond_destroy(&buf->playback_cond);
   pthread_cond_destroy(&buf->write_cond);
+#endif
 }
 
 
