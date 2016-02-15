--- src/develop/masks/path.c.orig	2016-02-02 11:36:06 UTC
+++ src/develop/masks/path.c
@@ -2555,8 +2555,8 @@ static int dt_path_get_mask_roi(dt_iop_m
   // now check if feather is at least partially within roi
   for(int i = nb_corner * 3; i < border_count; i++)
   {
-    int xx = border[i * 2];
-    int yy = border[i * 2 + 1];
+    float xx = border[i * 2];
+    float yy = border[i * 2 + 1];
     if(isnan(xx))
     {
       if(isnan(yy)) break; // that means we have to skip the end of the border path
