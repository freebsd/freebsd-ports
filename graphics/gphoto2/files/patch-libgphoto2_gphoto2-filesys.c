--- libgphoto2/gphoto2-filesys.c.orig	Sat Aug 31 20:30:42 2002
+++ libgphoto2/gphoto2-filesys.c	Sat Aug 31 20:32:23 2002
@@ -98,12 +98,12 @@
         /*
          * HP PhotoSmart C30 has the date and time in ifd_exif.
          */
-	e = exif_content_get_entry (ed->ifd0, EXIF_TAG_DATE_TIME);
+	e = exif_content_get_entry (ed->ifd[EXIF_IFD_0], EXIF_TAG_DATE_TIME);
 	if (!e)
-	        e = exif_content_get_entry (ed->ifd_exif,
+	    	e = exif_content_get_entry (ed->ifd[EXIF_IFD_EXIF],
 					    EXIF_TAG_DATE_TIME_ORIGINAL);
 	if (!e)
-		e = exif_content_get_entry (ed->ifd_exif, 
+	    	e = exif_content_get_entry (ed->ifd[EXIF_IFD_EXIF],
 					    EXIF_TAG_DATE_TIME_DIGITIZED);
         if (!e) {
                 GP_DEBUG ("EXIF data has not date/time tag.");
