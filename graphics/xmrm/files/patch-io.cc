--- io.cc.orig	Tue Mar 10 07:00:00 1998
+++ io.cc	Sun Nov 13 16:19:00 2005
@@ -87,7 +87,7 @@
 extern ControlClass control;
 
 /* Constructor: */
-ControlClass::ControlClass()
+void ControlClass::ControlClassInit()
 {
   int i;
  
@@ -301,7 +301,7 @@
     raster = pic->GetPicPointer();
 
     // Reading TIFF-Image into memory:
-    if ( (TIFFReadRGBAImage(tif,tif_w,tif_h,raster,0))==0 )
+    if ( (TIFFReadRGBAImage(tif,tif_w,tif_h,(uint32*)raster,0))==0 )
     {
       TIFFClose(tif);
       return 1;
@@ -435,7 +435,7 @@
     
     // Reading TIFF-Image into memory:                    bit 24  16   8   0
     // Internal raster-format: one unsigned long per pixel: | a | b | g | r |
-    if ( (TIFFReadRGBAImage(tif,tif_w,tif_h,raster,0))==0 )
+    if ( (TIFFReadRGBAImage(tif,tif_w,tif_h,(uint32*)raster,0))==0 )
     {
       TIFFClose(tif);
       return 1;
@@ -573,7 +573,7 @@
   TIFFSetField(tif,TIFFTAG_IMAGELENGTH,size_h);
   TIFFSetField(tif,TIFFTAG_BITSPERSAMPLE,8);
   TIFFSetField(tif,TIFFTAG_SAMPLESPERPIXEL,4);
-  TIFFSetField(tif,TIFFTAG_COMPRESSION,COMPRESSION_LZW); // free for non-commercial use (so I read)
+  TIFFSetField(tif,TIFFTAG_COMPRESSION,COMPRESSION_DEFLATE);
   TIFFSetField(tif,TIFFTAG_PLANARCONFIG,PLANARCONFIG_CONTIG);
   TIFFSetField(tif,TIFFTAG_PHOTOMETRIC,PHOTOMETRIC_RGB);
   TIFFSetField(tif,TIFFTAG_ORIENTATION,ORIENTATION_TOPLEFT);
@@ -592,8 +592,8 @@
 
   TIFFClose(tif);
   
-  extension = NULL;
-  filename_only = NULL;
+  extension = (char*)NULL;
+  filename_only = (char*)NULL;
   free(savename);
 }
 
@@ -644,7 +644,7 @@
   }
   
   // Reading TIFF-Image into memory:
-  if ( (TIFFReadRGBAImage(tif,tif_w,tif_h,raster,0))==0 )
+  if ( (TIFFReadRGBAImage(tif,tif_w,tif_h,(uint32*)raster,0))==0 )
   {
     fl_show_alert("ERROR:","Unable to load Detail-map:",filename,1);
     TIFFClose(tif);
@@ -930,7 +930,7 @@
       (void) strcpy( directory, filename );
       help = strrchr(directory, '/');
       *(++help) = '\0';
-      help = NULL;
+      help = (char*)NULL;
     }
 
   if( !filename )
@@ -1154,7 +1154,9 @@
     if ( proj.akima_points[i][0] < 0.0 || proj.akima_points[i][0] > 1.0 ||\
          proj.akima_points[i][1] < 0.0 || proj.akima_points[i][1] > 1.0 )
       wrong_value = TRUE;
-    control.akima_P[i] = proj.akima_points[i];
+
+    control.akima_P[i][0] = proj.akima_points[i][0];
+    control.akima_P[i][1] = proj.akima_points[i][1];
   }
   if( wrong_value || control.akima_nr < AKIMA_MIN || control.akima_nr > AKIMA_MAX )
   {
@@ -1387,9 +1389,10 @@
     proj.wavelets[0] = control.b_bias_val[0];
 
   proj.akima_nr = control.akima_nr;
-  for ( i = 0; i < control.akima_nr; i++)
-    proj.akima_points[i] = control.akima_P[i];
-
+  for ( i = 0; i < control.akima_nr; i++) {
+    proj.akima_points[i][0] = control.akima_P[i][0];
+    proj.akima_points[i][1] = control.akima_P[i][1];
+  }
   proj.weight_a = control.warp_a;
   proj.weight_b = control.warp_b;
   proj.weight_p = control.warp_p;
@@ -1407,16 +1410,16 @@
   fprintf(fp,"%s\n\n", PROJECT_FILE_V20_ID);
   help = strrchr(proj.filename_source, '/');
   fprintf(fp,"[Source_Image]\n%s\n\n", help ? ++help : proj.filename_source);
-  help = NULL;
+  help = (char*)NULL;
   help = strrchr(proj.filename_destination, '/');
   fprintf(fp,"[Destination_Image]\n%s\n\n", help ? ++help : proj.filename_destination);
 //  help = NULL;
 //  help = strrchr(proj.filename_vector, '/');
 //  fprintf(fp,"[Vector_File]\n%s\n\n", help ? ++help : proj.filename_vector);
-  help = NULL;
+  help = (char*)NULL;
   help = strrchr(proj.filename_area_map, '/');
   fprintf(fp,"[Detail_Map]\n%s\n\n", help ? ++help : proj.filename_area_map);
-  help = NULL;
+  help = (char*)NULL;
   fprintf(fp,"[Morph_Mode]\n%i\n\n", proj.morph_mode);
   fprintf(fp,"[Border_Vectors]\n%i\n\n", proj.border_vecs);
   fprintf(fp,"[Use_Wavelets]\n%i\n\n", proj.use_wavelets);
@@ -1543,7 +1546,7 @@
   switch(arg)
   {  
   case 1: // Load_Source
-    switch (ReadPicture( NULL, s_pic, 1 ))
+    switch (ReadPicture( (const char*)NULL, s_pic, 1 ))
     {
       case 1:// io error
         fl_show_alert("ERROR:","Cannot load Source image !","",1);
@@ -1576,7 +1579,7 @@
       return;
     }
 
-    switch (ReadPicture( NULL, d_pic, 0 ))
+    switch (ReadPicture( (const char*)NULL, d_pic, 0 ))
     {
       case 1:// io error
         fl_show_alert("ERROR:","Cannot load Destination image !","",1);
@@ -1616,7 +1619,7 @@
       }
     }
     
-    switch ( Load_Vectors(NULL) )
+    switch ( Load_Vectors((const char*)NULL) )
     {
       case 0:// OK
         control.vec_changed=0;
@@ -1720,7 +1723,7 @@
 //    extension--;
     
     i=0;
-    number = ".000.";
+    strcpy(number, ".000.");
     while ( !(extension = strstr(extension,number)) && i<=999 )
     {
       i++;
@@ -2217,7 +2220,7 @@
 //case 16-25: See default-branch !!!
     
   case 28:// OpenProject:
-    Load_Project(NULL);
+    Load_Project((const char*)NULL);
     break;
     
   case 29:// Save_Project
@@ -2235,7 +2238,7 @@
       return;
     }
   
-    if ( ReadAreaMap(NULL, area)==0 )
+    if ( ReadAreaMap((const char*)NULL, area)==0 )
     {
       fl_set_button(fd_MRM->CB_Area_Morph,1);
       fl_call_object_callback(fd_MRM->CB_Area_Morph);
@@ -2336,20 +2339,20 @@
     break;
   
   case 37:// BT_Drop:
-    sprintf(cmdbuf,"netscape %s &", control.URL_CG_Home);
+    sprintf(cmdbuf,"%s %s &", BROWSER_CMD, control.URL_CG_Home);
     test = system(cmdbuf);
     if ( test==-1 || test==127 )
     {
-      fl_show_alert("ERROR:","Execution of Netscape failed !","",1);
+      fl_show_alert("ERROR:","Execution of Browser failed !","",1);
     }
     break;
 
   case 38:// BT_TU_Logo:
-    sprintf(cmdbuf,"netscape %s &", control.URL_TU_Vienna);
+    sprintf(cmdbuf,"%s %s &", BROWSER_CMD, control.URL_TU_Vienna);
     test = system(cmdbuf);
     if ( test==-1 || test==127 )
     {
-      fl_show_alert("ERROR:","Execution of Netscape failed !","",1);
+      fl_show_alert("ERROR:","Execution of Browser failed !","",1);
     }
     break;
   
@@ -2599,11 +2602,11 @@
       switch (item)
       {
         case 1://Manual (Netscape)
-          sprintf(cmdbuf,"netscape %s &", control.URL_manual);
+          sprintf(cmdbuf,"%s %s &", BROWSER_CMD, control.URL_manual);
           test = system(cmdbuf);
           if ( test==-1 || test==127 )
           {
-            fl_show_alert("ERROR:","Execution of Netscape failed !","",1);
+            fl_show_alert("ERROR:","Execution of Browser failed !","",1);
           }
           break;
         case 2://About
