--- render.c.orig	2013-01-22 17:23:39.000000000 +0100
+++ render.c	2013-01-22 17:23:03.000000000 +0100
@@ -19,7 +19,7 @@
 
 struct render_thread_s {
   GThreadPool* pool; /**< Pool of threads */
-  GMutex mutex; /**< Render lock */
+  GStaticMutex mutex; /**< Render lock */
   bool about_to_close; /**< Render thread is to be freed */
 };
 
@@ -51,7 +51,7 @@
 
   render_thread->about_to_close = false;
   g_thread_pool_set_sort_function(render_thread->pool, render_thread_sort, zathura);
-  g_mutex_init(&render_thread->mutex);
+  g_static_mutex_init(&render_thread->mutex);
 
   return render_thread;
 
@@ -328,7 +328,7 @@
     return;
   }
 
-  g_mutex_lock(&render_thread->mutex);
+  g_static_mutex_lock(&render_thread->mutex);
 }
 
 void
@@ -338,5 +338,5 @@
     return;
   }
 
-  g_mutex_unlock(&render_thread->mutex);
+  g_static_mutex_unlock(&render_thread->mutex);
 }
