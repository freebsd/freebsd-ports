--- io.cc.orig	Tue Mar 10 00:00:00 1998
+++ io.cc	Fri Nov 29 18:01:04 2002
@@ -87,7 +87,7 @@
 extern ControlClass control;
 
 /* Constructor: */
-ControlClass::ControlClass()
+void ControlClass::ControlClassInit()
 {
   int i;
  
@@ -573,7 +573,7 @@
   TIFFSetField(tif,TIFFTAG_IMAGELENGTH,size_h);
   TIFFSetField(tif,TIFFTAG_BITSPERSAMPLE,8);
   TIFFSetField(tif,TIFFTAG_SAMPLESPERPIXEL,4);
-  TIFFSetField(tif,TIFFTAG_COMPRESSION,COMPRESSION_LZW); // free for non-commercial use (so I read)
+  TIFFSetField(tif,TIFFTAG_COMPRESSION,COMPRESSION_DEFLATE);
   TIFFSetField(tif,TIFFTAG_PLANARCONFIG,PLANARCONFIG_CONTIG);
   TIFFSetField(tif,TIFFTAG_PHOTOMETRIC,PHOTOMETRIC_RGB);
   TIFFSetField(tif,TIFFTAG_ORIENTATION,ORIENTATION_TOPLEFT);
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
@@ -1720,7 +1723,7 @@
 //    extension--;
     
     i=0;
-    number = ".000.";
+    strcpy(number, ".000.");
     while ( !(extension = strstr(extension,number)) && i<=999 )
     {
       i++;
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
