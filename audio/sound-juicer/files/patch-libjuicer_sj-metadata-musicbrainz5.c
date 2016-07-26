--- libjuicer/sj-metadata-musicbrainz5.c.orig	2015-11-16 10:34:34 UTC
+++ libjuicer/sj-metadata-musicbrainz5.c
@@ -757,7 +757,7 @@ fill_tracks_from_medium (SjMetadataMusic
       if (*error != NULL) {
         track_details_free (track);
         g_list_free_full (tracks, (GDestroyNotify) track_details_free);
-        return NULL;
+        return;
       }
 
       if (track->duration == 0)
