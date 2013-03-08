--- atk-adaptor/accessible-cache.c.orig	2012-11-21 23:46:32.000000000 +0000
+++ atk-adaptor/accessible-cache.c	2012-11-21 23:47:06.000000000 +0000
@@ -362,7 +362,7 @@
           if (!child)
             {
               g_static_rec_mutex_unlock (&cache_mutex);
-              return;
+              return FALSE;
             }
 
           g_object_ref (child);
