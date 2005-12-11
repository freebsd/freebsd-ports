--- src/buoh-comic-loader.c.orig	Sun Dec 11 00:25:18 2005
+++ src/buoh-comic-loader.c	Sun Dec 11 00:25:39 2005
@@ -184,6 +184,7 @@
 	}
 
 	if (loader->thread_mutex) {
+		g_mutex_unlock (loader->thread_mutex);
 		g_mutex_free (loader->thread_mutex);
 		loader->thread_mutex = NULL;
 	}
