Index: src/gamebigmap.cpp
@@ -455,7 +455,7 @@
       if (new_view.w <= GameMap::getWidth() && 
 	  new_view.h <= GameMap::getHeight() && 
 	  new_view.w >= 0 && new_view.h >= 0)
-	zoom_view(-zoom_step);
+	zoom_view(-(const double)zoom_step);
     }
 }
 
