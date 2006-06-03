--- metadata/rb-metadata-gst.c.orig	Sat Jun  3 00:21:25 2006
+++ metadata/rb-metadata-gst.c	Sat Jun  3 00:21:34 2006
@@ -1068,7 +1068,7 @@ rb_metadata_load (RBMetaData *md,
 			g_set_error (error,
 				     RB_METADATA_ERROR,
 				     RB_METADATA_ERROR_NOT_AUDIO_IGNORE,
-				     NULL);
+				     " ");
 		}
 	} else {
 		/* yay, it worked */
