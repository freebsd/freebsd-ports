--- library/rb-library-main-thread.c.orig	Sat May 17 20:56:40 2003
+++ library/rb-library-main-thread.c	Sat May 17 20:56:47 2003
@@ -325,7 +325,7 @@
 			rb_echo_area_end_task (echoarea, taskid);
 		g_mutex_unlock (priv->lock);
 
-		g_usleep (10);
+		g_usleep (10000);
 	}
 
 	return NULL;
