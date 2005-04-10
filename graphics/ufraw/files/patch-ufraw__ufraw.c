--- ./ufraw_ufraw.c.orig	Sun Apr 10 15:19:43 2005
+++ ./ufraw_ufraw.c	Sun Apr 10 15:20:06 2005
@@ -123,7 +123,7 @@
         for (i=0; i<cfg->curveCount; i++)
             cfg->curve[i].black = cfg_default.curve[0].black;
     }
-    if (cfg->exposureLoad==load_auto) cfg->exposure = nan("");
+    if (cfg->exposureLoad==load_auto) cfg->exposure = __builtin_nanf("");
 
     if (image==NULL) return UFRAW_SUCCESS;
 
