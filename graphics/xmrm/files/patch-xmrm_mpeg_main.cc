--- xmrm_mpeg_main.cc.orig	Tue Mar 10 00:00:00 1998
+++ xmrm_mpeg_main.cc	Fri Nov 29 15:06:47 2002
@@ -8,6 +8,7 @@
 #include <forms.h>
 #include <unistd.h>
 #include "xmrm_mpeg.h"
+#include "const.h"
 
 #define MAX_PIC_NUM 999
 #define BORDER_WIDTH -1
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
