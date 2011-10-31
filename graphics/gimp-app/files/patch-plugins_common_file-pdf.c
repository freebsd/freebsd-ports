--- plug-ins/common/file-pdf.c.orig	2010-07-02 22:51:56.000000000 +0000
+++ plug-ins/common/file-pdf.c	2011-10-23 19:29:37.000000000 +0000
@@ -566,6 +566,84 @@ layer_from_pixbuf (gint32        image,
   return layer;
 }
 
+static void
+copy_cairo_surface_to_pixbuf (cairo_surface_t *surface,
+                              GdkPixbuf       *pixbuf)
+{
+  int cairo_width, cairo_height, cairo_rowstride;
+  unsigned char *pixbuf_data, *dst, *cairo_data;
+  int pixbuf_rowstride, pixbuf_n_channels;
+  unsigned int *src;
+  int x, y;
+
+  cairo_width = cairo_image_surface_get_width (surface);
+  cairo_height = cairo_image_surface_get_height (surface);
+  cairo_rowstride = cairo_image_surface_get_stride (surface);
+  cairo_data = cairo_image_surface_get_data (surface);
+
+  pixbuf_data = gdk_pixbuf_get_pixels (pixbuf);
+  pixbuf_rowstride = gdk_pixbuf_get_rowstride (pixbuf);
+  pixbuf_n_channels = gdk_pixbuf_get_n_channels (pixbuf);
+
+  if (cairo_width > gdk_pixbuf_get_width (pixbuf))
+    cairo_width = gdk_pixbuf_get_width (pixbuf);
+  if (cairo_height > gdk_pixbuf_get_height (pixbuf))
+    cairo_height = gdk_pixbuf_get_height (pixbuf);
+
+  for (y = 0; y < cairo_height; y++)
+    {
+      src = (unsigned int *) (cairo_data + y * cairo_rowstride);
+      dst = pixbuf_data + y * pixbuf_rowstride;
+
+      for (x = 0; x < cairo_width; x++)
+        {
+          dst[0] = (*src >> 16) & 0xff;
+          dst[1] = (*src >> 8) & 0xff;
+          dst[2] = (*src >> 0) & 0xff;
+
+          if (pixbuf_n_channels == 4)
+            dst[3] = (*src >> 24) & 0xff;
+
+          dst += pixbuf_n_channels;
+          src++;
+        }
+    }
+}
+
+static GdkPixbuf *
+render_page_to_pixbuf (PopplerPage *page,
+                       int          width,
+                       int          height,
+                       double       scale)
+{
+  GdkPixbuf *pixbuf;
+  cairo_surface_t *surface;
+  cairo_t *cr;
+
+  pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8, width, height);
+  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);
+  cr = cairo_create (surface);
+
+  cairo_save (cr);
+  cairo_translate (cr, 0.0, 0.0);
+
+  if (scale != 1.0)
+    cairo_scale (cr, scale, scale);
+
+  poppler_page_render (page, cr);
+  cairo_restore (cr);
+
+  cairo_set_operator (cr, CAIRO_OPERATOR_DEST_OVER);
+  cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
+  cairo_paint (cr);
+
+  cairo_destroy (cr);
+  copy_cairo_surface_to_pixbuf (surface, pixbuf);
+  cairo_surface_destroy (surface);
+
+  return pixbuf;
+}
+
 static gint32
 load_image (PopplerDocument        *doc,
             const gchar            *filename,
@@ -597,7 +675,7 @@ load_image (PopplerDocument        *doc,
       gdouble      page_width;
       gdouble      page_height;
 
-      GdkPixbuf   *buf;
+      GdkPixbuf   *pixbuf;
       gint         width;
       gint         height;
 
@@ -627,15 +705,13 @@ load_image (PopplerDocument        *doc,
           gimp_image_set_resolution (image_ID, resolution, resolution);
         }
 
-      buf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8, width, height);
+      pixbuf = render_page_to_pixbuf (page, width, height, scale);
 
-      poppler_page_render_to_pixbuf (page, 0, 0, width, height, scale, 0, buf);
-
-      layer_from_pixbuf (image_ID, page_label, i, buf,
+      layer_from_pixbuf (image_ID, page_label, i, pixbuf,
                          doc_progress, 1.0 / pages->n_pages);
 
       g_free (page_label);
-      g_object_unref (buf);
+      g_object_unref (pixbuf);
 
       doc_progress = (double) (i + 1) / pages->n_pages;
       gimp_progress_update (doc_progress);
@@ -712,11 +788,7 @@ get_thumbnail (PopplerDocument *doc,
       width  *= scale;
       height *= scale;
 
-      pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8,
-                               width, height);
-
-      poppler_page_render_to_pixbuf (page,
-                                     0, 0, width, height, scale, 0, pixbuf);
+      pixbuf = render_page_to_pixbuf (page, width, height, scale);
     }
 
   g_object_unref (page);
