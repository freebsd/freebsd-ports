--- libexif/exif-data.c.orig	Sun Mar 13 03:27:13 2005
+++ libexif/exif-data.c	Wed Apr 13 22:42:35 2005
@@ -231,7 +231,7 @@
 		 * the offset must be an even number. If we need to introduce
 		 * a padding byte, we set it to 0.
 		 */
-		if (s & 1) *ds++;
+		if (s & 1) (*ds)++;
 		*d = exif_mem_realloc (data->priv->mem, *d, *ds);
 		if (!*d) {
 			EXIF_LOG_NO_MEMORY (data->priv->log, "ExifData", *ds);
