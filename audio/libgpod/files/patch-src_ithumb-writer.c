--- src/ithumb-writer.c.orig	2011-07-24 11:08:03 UTC
+++ src/ithumb-writer.c
@@ -728,7 +728,7 @@ ithumb_writer_handle_rotation (GdkPixbuf *pixbuf, guin
   {
       return gdk_pixbuf_rotate_simple (pixbuf, *rotation);
   }
-  return g_object_ref (G_OBJECT (pixbuf));
+  return (GdkPixbuf *)(g_object_ref (G_OBJECT (pixbuf)));
 }
 
 /* On the iPhone, thumbnails are presented as squares in a grid.
@@ -968,7 +968,7 @@ ithumb_writer_write_thumbnail (iThumbWriter *writer, 
     else if (thumb->data_type == ITDB_THUMB_TYPE_PIXBUF)
     {
         Itdb_Thumb_Pixbuf *thumb_pixbuf = (Itdb_Thumb_Pixbuf *)thumb;
-        pixbuf = g_object_ref (G_OBJECT (thumb_pixbuf->pixbuf));
+        pixbuf = (GdkPixbuf *)(g_object_ref (G_OBJECT (thumb_pixbuf->pixbuf)));
     }
 
     if (pixbuf == NULL)
