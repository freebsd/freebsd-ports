--- app/batch.cpp.orig	Sat Sep 18 22:02:13 2004
+++ app/batch.cpp	Sat Sep 18 22:03:11 2004
@@ -618,9 +618,9 @@
     else if(type == Equalize)
         EqualizeImage(img);
     else if(type == IncContrast)
-        ContrastImage(img, true);
+        ContrastImage(img, (MagickBooleanType)true);
     else if(type == DecContrast)
-        ContrastImage(img, false);
+        ContrastImage(img, (MagickBooleanType)false);
     else if(type == Solarize)
         SolarizeImage(img, weight);
     else if(type == Threshold)
@@ -752,7 +752,7 @@
             save = false;
     }
     else if(type == Shade){
-        Image *tmp = ShadeImage(img, useColor, a, e, &exception);
+        Image *tmp = ShadeImage(img, (MagickBooleanType)useColor, a, e, &exception);
         if(tmp){
             if(img->next)
                 DestroyImageList(img);
