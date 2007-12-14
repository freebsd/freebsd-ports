--- src/pfshdrcalibrate.cpp.orig	Wed Aug 23 14:49:59 2006
+++ src/pfshdrcalibrate.cpp	Thu Jun 21 14:40:28 2007
@@ -108,7 +108,7 @@
     { "help", no_argument, NULL, 'h' },
     { "verbose", no_argument, NULL, 'v' },
     { "luminance", no_argument, NULL, 'Y' },
-    { "fillin-response", no_argument, NULL, 'F' },
+//    { "fillin-response", no_argument, NULL, 'F' },
     { "calibration", required_argument, NULL, 'c' },
     { "gauss", required_argument, NULL, 'g' },
     { "max-response", required_argument, NULL, 'A' },
@@ -123,7 +123,7 @@
 
   int optionIndex = 0;
   while( 1 ) {
-    int c = getopt_long (argc, argv, "hvYFc:g:r:f:s:m:b:", cmdLineOptions, &optionIndex);
+    int c = getopt_long (argc, argv, "hvYFc:g:r:f:s:m:b:S:A:", cmdLineOptions, &optionIndex);
     if( c == -1 ) break;
     switch( c ) {
     case 'h':
@@ -246,8 +246,8 @@
     throw pfs::Exception("calibration method not set or not supported");
   }
 
-  VERBOSE_STR << "interpolate missing parts of response: "
-              << (opt_fillgaps ? "yes" : "no") << endl;
+//   VERBOSE_STR << "interpolate missing parts of response: "
+//               << (opt_fillgaps ? "yes" : "no") << endl;
   
   if( responseSaveFile!=NULL )
     VERBOSE_STR << "save response curve to a file (do not generate HDR image)" << endl;
@@ -434,6 +434,8 @@
   pfs::Channel *Xj, *Yj, *Zj;
   frame->createXYZChannels( Xj, Yj, Zj );
 
+  // !!! this currently does more bad than good, relevant command line
+  // option is disabled
   if( opt_fillgaps )
   {
     if( opt_luminance )
@@ -453,42 +455,50 @@
   }
 
   // calibration
+  long sp = 0;                  // saturated pixels
   switch( opt_calibration )
   {
   case NONE:
     if( opt_luminance )
     {
       VERBOSE_STR << "applying response to Y channel..." << endl;
-      robertson02_applyResponse( Yj, imgsY, Iy, w, M);
+      sp = robertson02_applyResponse( Yj, imgsY, Iy, w, M);
     }
     else
     {
       VERBOSE_STR << "applying response to R channel..." << endl;
-      robertson02_applyResponse( Xj, imgsR, Ir, w, M);
+      sp = robertson02_applyResponse( Xj, imgsR, Ir, w, M);
       VERBOSE_STR << "applying response to G channel..." << endl;
-      robertson02_applyResponse( Yj, imgsG, Ig, w, M);
+      sp += robertson02_applyResponse( Yj, imgsG, Ig, w, M);
       VERBOSE_STR << "applying response to B channel..." << endl;
-      robertson02_applyResponse( Zj, imgsB, Ib, w, M);
+      sp += robertson02_applyResponse( Zj, imgsB, Ib, w, M);
+      sp /= 3;
     }
     break;
   case ROBERTSON:
     if( opt_luminance )
     {
       VERBOSE_STR << "recovering Y channel..." << endl;
-      robertson02_getResponse( Yj, imgsY, Iy, w, M);
+      sp = robertson02_getResponse( Yj, imgsY, Iy, w, M);
     }
     else
     {
       VERBOSE_STR << "recovering R channel..." << endl;
-      robertson02_getResponse( Xj, imgsR, Ir, w, M);
+      sp = robertson02_getResponse( Xj, imgsR, Ir, w, M);
       VERBOSE_STR << "recovering G channel..." << endl;
-      robertson02_getResponse( Yj, imgsG, Ig, w, M);
+      sp += robertson02_getResponse( Yj, imgsG, Ig, w, M);
       VERBOSE_STR << "recovering B channel..." << endl;
-      robertson02_getResponse( Zj, imgsB, Ib, w, M);
+      sp += robertson02_getResponse( Zj, imgsB, Ib, w, M);
+      sp /= 3;
     }
     break;
   case DEBEVEC:
     break;
+  }
+  if( sp>0 )
+  {
+    float perc = ceilf(100.0f*sp/size);
+    VERBOSE_STR << "saturated pixels found in " << perc << "% of the image!" << endl;
   }
 
   // save response curve to a given file
