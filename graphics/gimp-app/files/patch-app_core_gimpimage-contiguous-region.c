--- app/core/gimpimage-contiguous-region.c.orig	Wed Jan  7 15:13:01 2004
+++ app/core/gimpimage-contiguous-region.c	Wed Jan  7 15:20:20 2004
@@ -416,7 +416,7 @@
   guchar *m;
   guchar  s_color[MAX_CHANNELS];
   guchar  diff;
-  gint    col_bytes = bytes;;
+  gint    col_bytes = bytes;
   Tile   *s_tile    = NULL;
   Tile   *m_tile    = NULL;
 
