--- plug-ins/common/svg.c.orig	Sun Nov  6 14:24:49 2005
+++ plug-ins/common/svg.c	Sun Nov  6 14:25:01 2005
@@ -437,7 +437,7 @@ load_rsvg_pixbuf (const gchar  *filename
 
   handle = rsvg_handle_new ();
 
-#if (LIBRSVG_MAJOR_VERSION == 2 && LIBRSVG_MINOR_VERSION < 99)
+#if (LIBRSVG_MAJOR_VERSION == 2 && LIBRSVG_MINOR_VERSION < 13)
   rsvg_handle_set_dpi_x_y (handle, vals->resolution, vals->resolution);
 #else
   rsvg_handle_set_dpi (handle, vals->resolution, vals->resolution);
@@ -538,7 +538,7 @@ load_rsvg_size (const gchar  *filename,
 
   handle = rsvg_handle_new ();
 
-#if (LIBRSVG_MAJOR_VERSION == 2 && LIBRSVG_MINOR_VERSION < 99)
+#if (LIBRSVG_MAJOR_VERSION == 2 && LIBRSVG_MINOR_VERSION < 13)
   rsvg_handle_set_dpi_x_y (handle, vals->resolution, vals->resolution);
 #else
   rsvg_handle_set_dpi (handle, vals->resolution, vals->resolution);
