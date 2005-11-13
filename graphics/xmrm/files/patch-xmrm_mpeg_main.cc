--- xmrm_mpeg_main.cc.orig	Tue Mar 10 07:00:00 1998
+++ xmrm_mpeg_main.cc	Sun Nov 13 16:25:33 2005
@@ -8,6 +8,7 @@
 #include <forms.h>
 #include <unistd.h>
 #include "xmrm_mpeg.h"
+#include "const.h"
 
 #define MAX_PIC_NUM 999
 #define BORDER_WIDTH -1
@@ -50,11 +51,11 @@
 //------------------------------
 names_n_numbers::names_n_numbers()
 {
-  START_Frame = NULL;
-  START_fname_only = NULL;
-  END_Frame = NULL;
+  START_Frame = (char*)NULL;
+  START_fname_only = (char*)NULL;
+  END_Frame = (char*)NULL;
   
-  filename_ppm = filename_yuv = extension = NULL;
+  filename_ppm = filename_yuv = extension = (char*)NULL;
 
   abs_count = first_width = first_height = start_number = 0;
   end_number = MAX_PIC_NUM;
@@ -68,7 +69,7 @@
 {
   int count = 0;
 
-  backup_class->number_str = ".000.";
+  strcpy(backup_class->number_str, ".000.");
 
   while ( !(*ext = strstr(fname_only,backup_class->number_str)) && (count <= MAX_PIC_NUM) )
   {
@@ -329,7 +330,7 @@
       TIFFSetField(tif,TIFFTAG_IMAGELENGTH,even_height);
       TIFFSetField(tif,TIFFTAG_BITSPERSAMPLE,8);
       TIFFSetField(tif,TIFFTAG_SAMPLESPERPIXEL,4);
-      TIFFSetField(tif,TIFFTAG_COMPRESSION,COMPRESSION_LZW); // free for non-commercial use (so I read)
+      TIFFSetField(tif,TIFFTAG_COMPRESSION,COMPRESSION_DEFLATE);
       TIFFSetField(tif,TIFFTAG_PLANARCONFIG,PLANARCONFIG_CONTIG);
       TIFFSetField(tif,TIFFTAG_PHOTOMETRIC,PHOTOMETRIC_RGB);
       TIFFSetField(tif,TIFFTAG_ORIENTATION,ORIENTATION_TOPLEFT);
@@ -417,7 +418,7 @@
       // Check for even picture size
       if ( (tif_w % 2) || (tif_h % 2) )
       {
-        work_class->even = ".even";
+        strcpy(work_class->even,".even");
         if ( Even_Size( tif, tif_w, tif_h) )
           return 1;
       }
@@ -713,8 +714,8 @@
       break;
       
     case 2: // Choose Start/Stop Frame
-      backup_class->START_Frame = NULL;
-      backup_class->END_Frame = NULL;
+      backup_class->START_Frame = (char*)NULL;
+      backup_class->END_Frame = (char*)NULL;
 
       fl_hide_object(fd_CREATE_MPEG->BT_Go);
 
@@ -786,8 +787,8 @@
     }
 
   // redirect TIFF-Error- and Warnig-Handler
-  (void) TIFFSetErrorHandler(NULL);
-  (void) TIFFSetWarningHandler(NULL);
+  (TIFFErrorHandler) TIFFSetErrorHandler((TIFFErrorHandler)NULL);
+  (TIFFErrorHandler) TIFFSetWarningHandler((TIFFErrorHandler)NULL);
   
   // show the first form
   fl_hide_object(fd_CREATE_MPEG->BT_Go);
