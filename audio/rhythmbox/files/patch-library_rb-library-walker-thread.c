--- library/rb-library-walker-thread.c.orig	Sun Feb  9 13:09:48 2003
+++ library/rb-library-walker-thread.c	Sat May 17 21:02:36 2003
@@ -325,7 +325,7 @@
 
 		g_mutex_unlock (thread->priv->lock);
 
-		g_usleep (10);
+		g_usleep (10000);
 	}
 
 	return NULL;
