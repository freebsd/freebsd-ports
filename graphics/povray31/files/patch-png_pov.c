--- source/png_pov.c.orig	1999-05-01 15:01:24.000000000 +0200
+++ source/png_pov.c	2012-05-05 07:28:33.000000000 +0200
@@ -53,6 +53,7 @@
 #include "optout.h"
 #include "png.h"
 #include "png_pov.h"
+#include "pngpriv.h"
 
 
 
@@ -227,7 +228,7 @@
   if (png_get_error_ptr(png_ptr))
     Error_Line("libpng: %s\n",msg);
 
-  longjmp(png_ptr->jmpbuf,1);
+  longjmp(png_jmpbuf(png_ptr),1);
 }
 
 
@@ -356,7 +357,7 @@
         Error("Error allocating PNG data structures");
       }
 
-      if (setjmp(o_png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(o_png_ptr)))
       {
         /* If we get here, we had a problem reading the file */
         Status_Info("\n");
@@ -397,7 +398,7 @@
         Error("Error allocating PNG data structures");
       }
 
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         /* If we get here, we had a problem writing the file */
         Status_Info("\n");
@@ -509,7 +510,7 @@
         Error("Error allocating PNG data structures");
       }
 
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         /* If we get here, we had a problem writing the file */
         if (handle->buffer != NULL)
@@ -628,7 +629,7 @@
     case APPEND_MODE:
 
 #if defined(PNG_WRITE_FLUSH_SUPPORTED)
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         /* If we get here, we had a problem writing the file */
 
@@ -943,7 +944,7 @@
       }
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     /* If we get here, we had a problem writing the file */
     fclose(handle->file);
@@ -996,7 +997,7 @@
 {
   register int col, j, step;
 
-  if (setjmp(o_png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(o_png_ptr)))
   {
     /* If we get here, we had a problem reading the file, which probably
      * means that we have read all the available data, rather than a real
@@ -1006,7 +1007,7 @@
     return(0);
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     /* If we get here, we had a problem writing the new file */
     Status_Info("\n");
@@ -1139,7 +1140,7 @@
   {
     if (png_ptr != NULL)
     {
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
       {
         /* If we get here, we had a problem writing the file */
 
@@ -1391,7 +1392,7 @@
     return;	/* -hdf99- */
   }
 
-  if (setjmp(r_png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(r_png_ptr)))
   {
     /* If we get here, we had a problem reading the file */
 
@@ -1445,7 +1446,7 @@
     if (r_info_ptr->valid & PNG_INFO_tRNS)
     {
       for (index = 0; index < r_info_ptr->num_trans; index++)
-        cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+        cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
     }
 
     Image->data.map_lines = (unsigned char **)
@@ -1479,7 +1480,7 @@
     if (r_info_ptr->valid & PNG_INFO_tRNS)
     {
       for (index = 0; index < r_info_ptr->num_trans; index++)
-        cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+        cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
     }
 
     Image->data.map_lines = (unsigned char **)
