--- source/png_pov.cpp.orig	2005-08-23 21:20:33.000000000 +0200
+++ source/png_pov.cpp	2012-05-06 19:21:51.000000000 +0200
@@ -54,6 +54,7 @@
 #include "povray.h"
 #include "optout.h"
 #include "png.h"
+#include "pngpriv.h"
 #include "png_pov.h"
 #include "pov_util.h"
 #include "povmsend.h"
@@ -172,7 +173,7 @@
 	  if (png_get_error_ptr(png_ptr))
 	   PossibleError("libpng: %s",msg);
 
-	  longjmp(png_ptr->jmpbuf,1);
+	  longjmp(png_jmpbuf(png_ptr),1);
 	}
 
 
@@ -392,7 +393,7 @@
         Error("Cannot allocate PNG data structures");
       }
 
-      if (setjmp(o_png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(o_png_ptr)))
       {
         // If we get here, we had a problem reading the file 
         png_destroy_read_struct(&o_png_ptr, &info_ptr, (png_infopp)NULL);
@@ -442,7 +443,7 @@
         Error("Cannot allocate PNG data structures");
       }
 
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         // If we get here, we had a problem writing the file 
         png_destroy_read_struct(&o_png_ptr, &info_ptr, (png_infopp)NULL);
@@ -538,7 +539,7 @@
         Error("Cannot allocate PNG data structures");
       }
 
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         // If we get here, we had a problem writing the file 
         png_destroy_write_struct(&png_ptr, &info_ptr);
@@ -656,7 +657,7 @@
     case APPEND_MODE:
 
 #if defined(PNG_WRITE_FLUSH_SUPPORTED)
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         // If we get here, we had a problem writing the file 
 
@@ -765,7 +766,7 @@
 
     if (png_ptr != NULL)
     {
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         // If we get here, we had a problem writing the file 
 
@@ -1213,7 +1214,7 @@
       }
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     // If we get here, we had a problem writing the file 
     delete out_file;
@@ -1261,7 +1262,7 @@
 
   register int col, j, step;
 
-  if (setjmp(o_png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(o_png_ptr)))
   {
     /* If we get here, we had a problem reading the file, which probably
      * means that we have read all the available data, rather than a real
@@ -1270,7 +1271,7 @@
     return 0;
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     // If we get here, we had a problem writing the new file 
     delete in_file;
@@ -1386,7 +1387,7 @@
 	   ((r_info_ptr = png_create_info_struct(r_png_ptr)) == NULL))
 		Error("Cannot allocate PNG data structures");
 
-	if(setjmp(r_png_ptr->jmpbuf))
+	if(setjmp(png_jmpbuf(r_png_ptr)))
 	{
 		// If we get here, we had a problem reading the file 
 		png_destroy_read_struct(&r_png_ptr, &r_info_ptr, (png_infopp)NULL);
@@ -1437,7 +1438,7 @@
 		if(r_info_ptr->valid & PNG_INFO_tRNS)
 		{
 			for (index = 0; index < r_info_ptr->num_trans; index++)
-				cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+				cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
 		}
 
 		Image->data.map_lines = (unsigned char **)POV_MALLOC(height * sizeof(unsigned char *), "PNG image");
@@ -1470,7 +1471,7 @@
 		if(r_info_ptr->valid & PNG_INFO_tRNS)
 		{
 			for (index = 0; index < r_info_ptr->num_trans; index++)
-				cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+				cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
 		}
 
 		Image->data.map_lines = (unsigned char **)POV_MALLOC(height * sizeof(unsigned char *), "PNG image");
