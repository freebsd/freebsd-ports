--- source/png_pov.cpp.orig	2004-08-03 01:11:37.000000000 +0200
+++ source/png_pov.cpp	2012-05-05 07:35:49.000000000 +0200
@@ -53,6 +53,7 @@
 #include "pov_util.h"
 #include "povmsend.h"
 #include "colour.h"
+#include "pngpriv.h"
 
 USING_POV_NAMESPACE
 
@@ -167,7 +168,7 @@
 	  if (png_get_error_ptr(png_ptr))
 	   PossibleError("libpng: %s",msg);
 
-	  longjmp(png_ptr->jmpbuf,1);
+	  longjmp(png_jmpbuf(png_ptr),1);
 	}
 
 
@@ -387,7 +388,7 @@
         Error("Cannot allocate PNG data structures");
       }
 
-      if (setjmp(o_png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(o_png_ptr)))
       {
         // If we get here, we had a problem reading the file 
         png_destroy_read_struct(&o_png_ptr, &info_ptr, (png_infopp)NULL);
@@ -433,7 +434,7 @@
         Error("Cannot allocate PNG data structures");
       }
 
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         // If we get here, we had a problem writing the file 
         png_destroy_read_struct(&o_png_ptr, &info_ptr, (png_infopp)NULL);
@@ -529,7 +530,7 @@
         Error("Cannot allocate PNG data structures");
       }
 
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         // If we get here, we had a problem writing the file 
         png_destroy_write_struct(&png_ptr, &info_ptr);
@@ -647,7 +648,7 @@
     case APPEND_MODE:
 
 #if defined(PNG_WRITE_FLUSH_SUPPORTED)
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         // If we get here, we had a problem writing the file 
 
@@ -756,7 +757,7 @@
 
     if (png_ptr != NULL)
     {
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         // If we get here, we had a problem writing the file 
 
@@ -1204,7 +1205,7 @@
       }
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     // If we get here, we had a problem writing the file 
     delete out_file;
@@ -1252,7 +1253,7 @@
 
   register int col, j, step;
 
-  if (setjmp(o_png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(o_png_ptr)))
   {
     /* If we get here, we had a problem reading the file, which probably
      * means that we have read all the available data, rather than a real
@@ -1261,7 +1262,7 @@
     return 0;
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     // If we get here, we had a problem writing the new file 
     delete in_file;
@@ -1377,7 +1378,7 @@
 	   ((r_info_ptr = png_create_info_struct(r_png_ptr)) == NULL))
 		Error("Cannot allocate PNG data structures");
 
-	if(setjmp(r_png_ptr->jmpbuf))
+	if(setjmp(png_jmpbuf(r_png_ptr)))
 	{
 		// If we get here, we had a problem reading the file 
 		png_destroy_read_struct(&r_png_ptr, &r_info_ptr, (png_infopp)NULL);
@@ -1428,7 +1429,7 @@
 		if(r_info_ptr->valid & PNG_INFO_tRNS)
 		{
 			for (index = 0; index < r_info_ptr->num_trans; index++)
-				cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+				cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
 		}
 
 		Image->data.map_lines = (unsigned char **)POV_MALLOC(height * sizeof(unsigned char *), "PNG image");
@@ -1461,7 +1462,7 @@
 		if(r_info_ptr->valid & PNG_INFO_tRNS)
 		{
 			for (index = 0; index < r_info_ptr->num_trans; index++)
-				cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+				cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
 		}
 
 		Image->data.map_lines = (unsigned char **)POV_MALLOC(height * sizeof(unsigned char *), "PNG image");
