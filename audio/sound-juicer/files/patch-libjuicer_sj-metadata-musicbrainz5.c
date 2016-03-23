--- libjuicer/sj-metadata-musicbrainz5.c.orig	2015-08-17 21:51:58.000000000 +0200
+++ libjuicer/sj-metadata-musicbrainz5.c	2015-08-17 21:52:28.000000000 +0200
@@ -757,7 +757,7 @@
       if (*error != NULL) {
         track_details_free (track);
         g_list_free_full (tracks, (GDestroyNotify) track_details_free);
-        return NULL;
+        return;
       }
 
       if (track->duration == 0)
