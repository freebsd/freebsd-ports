--- src/prevman.c	2014-03-27 20:00:17.000000000 -0300
+++ src/prevman.c	2014-03-27 20:00:23.000000000 -0300
@@ -52,7 +52,7 @@
   tile_source->width = drawable->width;
   tile_source->height = drawable->height;
   tile_source->bpp = drawable->bpp;
-  tile_source->has_alpha = gimp_drawable_has_alpha (drawable->id);
+  tile_source->has_alpha = gimp_drawable_has_alpha (drawable->drawable_id);
   tile_source->un.drw.drawable = drawable;
   gimp_pixel_rgn_init (&tile_source->un.drw.pixel_rgn, drawable, x, y, width,
                        height, FALSE, FALSE);
@@ -144,7 +144,7 @@
   tile_sink->width = drawable->width;
   tile_sink->height = drawable->height;
   tile_sink->bpp = drawable->bpp;
-  tile_sink->has_alpha = gimp_drawable_has_alpha (drawable->id);
+  tile_sink->has_alpha = gimp_drawable_has_alpha (drawable->drawable_id);
   gimp_pixel_rgn_init (&tile_sink->un.drw.pixel_rgn, drawable, x, y, width,
                        height, TRUE, TRUE);
 }
@@ -159,7 +159,7 @@
   tile_sink->width = width;
   tile_sink->height = height;
   tile_sink->bpp = drawable->bpp;
-  tile_sink->has_alpha = gimp_drawable_has_alpha (drawable->id);
+  tile_sink->has_alpha = gimp_drawable_has_alpha (drawable->drawable_id);
   tile_sink->un.prv.data = g_new (guchar,
                                   tile_sink->width * tile_sink->height *
                                   tile_sink->bpp);
