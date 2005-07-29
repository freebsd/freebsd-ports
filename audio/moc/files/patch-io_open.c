Index: io.c
===================================================================
--- io.c	(revision 1506)
+++ io.c	(revision 1507)
@@ -300,16 +300,6 @@
 		if (s->source == IO_SOURCE_FD)
 			close (s->fd);
 
-		if (pthread_mutex_destroy(&s->buf_mutex))
-			logit ("Destroying buf_mutex failed: %s",
-					strerror(errno));
-		if (pthread_mutex_destroy(&s->io_mutex))
-			logit ("Destroying io_mutex failed: %s",
-					strerror(errno));
-		if (pthread_mutex_destroy(&s->metadata.mutex))
-			logit ("Destroying metadata mutex failed: %s",
-					strerror(errno));
-
 		if (s->buffered) {
 			fifo_buf_destroy (&s->buf);
 			if (pthread_cond_destroy(&s->buf_free_cond))
@@ -326,6 +316,13 @@
 			free (s->metadata.url);
 	}
 
+	if (pthread_mutex_destroy(&s->buf_mutex))
+		logit ("Destroying buf_mutex failed: %s", strerror(errno));
+	if (pthread_mutex_destroy(&s->io_mutex))
+		logit ("Destroying io_mutex failed: %s", strerror(errno));
+	if (pthread_mutex_destroy(&s->metadata.mutex))
+		logit ("Destroying metadata mutex failed: %s", strerror(errno));
+
 	if (s->strerror)
 		free (s->strerror);
 	free (s);
@@ -493,6 +490,10 @@
 #endif
 	io_open_file (s, file);
 
+	pthread_mutex_init (&s->buf_mutex, NULL);
+	pthread_mutex_init (&s->io_mutex, NULL);
+	pthread_mutex_init (&s->metadata.mutex, NULL);
+
 	if (!s->opened)
 		return s;
 				
@@ -503,10 +504,6 @@
 	s->pos = 0;
 	memset (&s->metadata, 0, sizeof(s->metadata));
 
-	pthread_mutex_init (&s->buf_mutex, NULL);
-	pthread_mutex_init (&s->io_mutex, NULL);
-	pthread_mutex_init (&s->metadata.mutex, NULL);
-
 	if (buffered) {
 		fifo_buf_init (&s->buf, options_get_int("InputBuffer") * 1024);
 		s->prebuffer = options_get_int("Prebuffering") * 1024;
