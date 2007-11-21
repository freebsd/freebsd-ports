--- src/mp4file.c.orig	2007-11-02 18:19:06.000000000 +0200
+++ src/mp4file.c	2007-11-02 18:19:59.000000000 +0200
@@ -149,7 +149,7 @@
     g_return_val_if_fail (mp4File != MP4_INVALID_FILE_HANDLE, FALSE);
 
     if (MP4GetMetadataFreeForm(mp4File, "iTunNORM",
-			       &ppValue, &pValueSize))
+			       &ppValue, &pValueSize, NULL))
     {
 	gchar *str;
 	guint sc1=0, sc2=0;
@@ -171,7 +171,7 @@
     }
 
     if (MP4GetMetadataFreeForm(mp4File, "replaygain_track_gain",
-			       &ppValue, &pValueSize))
+			       &ppValue, &pValueSize, NULL))
     {
 	gchar *str;
 	gdouble rg;
@@ -367,7 +367,7 @@
 		    u_int8_t *image_data;
 		    u_int32_t image_data_len;
 		    if (MP4GetMetadataCoverArt (mp4File,
-						&image_data, &image_data_len))
+						&image_data, &image_data_len, 0))
 		    {
 			if (image_data)
 			{
@@ -452,7 +452,7 @@
 	    MP4GetMetadataAlbum (mp4File, &m_album);
 	    MP4GetMetadataGenre (mp4File, &m_genre);*/
 	    MP4GetMetadataTool (mp4File, &m_tool);
-	    MP4GetMetadataCoverArt (mp4File, &m_covert, &m_size);
+	    MP4GetMetadataCoverArt (mp4File, &m_covert, &m_size, 0);
 	    MP4MetadataDelete (mp4File);
 #endif
 	    value = charset_from_utf8 (track->title);
