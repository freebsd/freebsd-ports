--- plug-ins/common/file-dicom.c.orig	2022-06-12 20:26:00 UTC
+++ plug-ins/common/file-dicom.c
@@ -602,7 +602,7 @@ load_image (const gchar  *filename,
                                (gchar *) value, samples_per_pixel);
                   g_free (dicominfo);
                   fclose (DICOM);
-                  return NULL;
+                  return -1;
                 }
 
               break;
