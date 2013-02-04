--- mahjongg.c.orig
+++ mahjongg.c
@@ -41,6 +41,7 @@
  */
 
 #include <stdio.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <xview/xview.h>
@@ -1178,7 +1179,7 @@
     tileptr->y_loc = y_loc;
 
     if (tileptr->removed)
-	return;
+	return(0);
 
     if (! tileptr->top_covered)
 	if (Use_tile_server_images)
@@ -1245,7 +1246,7 @@
 Pixrect *pr;
 {
     if (PIXRECT_IMAGE_DEPTH(pr) <= 1)
-	return;
+	return(0);
 
     shift_image_colors( PIXRECT_IMAGE_DATA_PTR(pr),
 			PIXRECT_IMAGE_SIZE(pr) );
