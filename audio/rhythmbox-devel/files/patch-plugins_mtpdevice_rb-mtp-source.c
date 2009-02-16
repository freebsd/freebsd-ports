--- plugins/mtpdevice/rb-mtp-source.c.orig	2009-02-15 22:33:07.000000000 +0900
+++ plugins/mtpdevice/rb-mtp-source.c	2009-02-15 22:35:14.000000000 +0900
@@ -357,7 +357,7 @@
 
 	g_assert (db != NULL);
 
-	tracks = LIBMTP_Get_Tracklisting (priv->device);
+	tracks = LIBMTP_Get_Tracklisting_With_Callback (priv->device, NULL, NULL);
 	if (tracks != NULL) {
 		LIBMTP_track_t *track, *tmp = NULL;
 		for (track = tracks; track != NULL; track = track->next) {
@@ -714,7 +714,7 @@
 		trackmeta->filetype = mimetype_to_filetype (mimetype);
 	}
 
-	if (LIBMTP_Send_Track_From_File (device, filename, trackmeta, NULL, NULL, 0) != 0) {
+	if (LIBMTP_Send_Track_From_File (device, filename, trackmeta, NULL, NULL) != 0) {
 		LIBMTP_destroy_track_t (trackmeta);
 		rb_debug ("Tracktransfer failed\n");
 		return NULL;
