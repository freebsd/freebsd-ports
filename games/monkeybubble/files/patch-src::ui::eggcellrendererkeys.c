--- src/ui/eggcellrendererkeys.c.orig	Fri Aug 13 14:50:55 2004
+++ src/ui/eggcellrendererkeys.c	Fri Aug 13 14:51:54 2004
@@ -588,7 +588,7 @@
 void
 egg_cell_renderer_keys_set_accelerator (EggCellRendererKeys *keys,
                                         guint                keyval,
-                                        GdkModifierType      mask)
+                                        EggVirtualModifierType      mask)
 {
   char *text;
   gboolean changed;
@@ -630,7 +630,7 @@
 void
 egg_cell_renderer_keys_get_accelerator (EggCellRendererKeys *keys,
                                         guint               *keyval,
-                                        GdkModifierType     *mask)
+                                        EggVirtualModifierType     *mask)
 {
   g_return_if_fail (EGG_IS_CELL_RENDERER_KEYS (keys));
 
