--- src/Plugins/Freetype/tt_font.cpp.orig	Tue Oct 28 11:00:51 2003
+++ src/Plugins/Freetype/tt_font.cpp	Thu Nov 20 01:06:15 2003
@@ -167,7 +167,7 @@
     E->y3= dy - hh;
     E->x4= dx + ww;
     E->y4= dy;
-    T[i]= E;
+    memcpy(T[i], E, sizeof(E));
   }
   bmm= new bitmap_metric_rep (res_name, T, 0, 255);
   bmf= new bitmap_font_rep   (res_name, B, 0, 255);
