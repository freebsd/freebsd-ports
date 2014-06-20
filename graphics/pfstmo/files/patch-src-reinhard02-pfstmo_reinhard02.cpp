--- src/reinhard02/pfstmo_reinhard02.cpp.orig	2008-09-04 12:46:49.000000000 +0000
+++ src/reinhard02/pfstmo_reinhard02.cpp	2014-06-18 15:29:52.318951701 +0000
@@ -33,6 +33,7 @@
 
 #include <config.h>
 
+#include <exception>
 #include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
@@ -40,8 +41,9 @@
 #include <math.h>
 
 #include <pfs.h>
+#include <pfstmo.h>
 
-#include <tmo_reinhard02.h>
+#include "tmo_reinhard02.h"
 
 using namespace std;
 
@@ -61,6 +63,7 @@
     "\t[--key <val>] [--phi <val>] \n"
     "\t[--range <val>] [--lower <val>] [--upper <val>] \n"
     "\t[--temporal-coherent]\n"
+    "\t[--border <val>] \n"
     "\t[--verbose] [--help] \n"
     "See man page for more information.\n" );
 }
@@ -77,6 +80,7 @@
   int high = 43;
   bool use_scales = false;
   bool temporal_coherent = false;  
+  float border = 0.f;
 
   static struct option cmdLineOptions[] = {
     { "help", no_argument, NULL, 'h' },
@@ -88,12 +92,13 @@
     { "lower", required_argument, NULL, 'l' },
     { "upper", required_argument, NULL, 'u' },
     { "temporal-coherent", no_argument, NULL, 't' },
+    { "border", required_argument, NULL, 'b' },
     { NULL, 0, NULL, 0 }
   };
 
   int optionIndex = 0;
   while( 1 ) {
-    int c = getopt_long (argc, argv, "hvsk:p:r:l:u:t", cmdLineOptions, &optionIndex);
+    int c = getopt_long (argc, argv, "hvsk:p:r:l:u:tb:", cmdLineOptions, &optionIndex);
     if( c == -1 ) break;
     switch( c ) {
     case 'h':
@@ -133,6 +138,11 @@
     case 't':
       temporal_coherent = true;
       break;
+    case 'b':
+      border = (float)strtod( optarg, NULL );
+      if( border<0.0f || border>=0.5f )
+        throw pfs::Exception("border width value out of range, should be >=0 and <0.5");
+      break;
     case '?':
       throw QuietException();
     case ':':
@@ -140,17 +150,23 @@
     }
   }
 
-  VERBOSE_STR << "use scales: " << (use_scales ? "yes" : "no" ) << endl;
   VERBOSE_STR << "key value: " << key << endl;
-  VERBOSE_STR << "phi value: " << phi << endl;
+  VERBOSE_STR << "use scales: " << (use_scales ? "yes" : "no" ) << endl;
   if( use_scales )
   {
-    VERBOSE_STR << "number of scales: " << num << endl;
-    VERBOSE_STR << "lower scale size: " << low << endl;
-    VERBOSE_STR << "upper scale size: " << high << endl;
 #ifndef HAVE_ZFFT
     VERBOSE_STR << "approximate implementation of scales" << endl;
 #endif
+    VERBOSE_STR << "number of scales: " << num << endl;
+    VERBOSE_STR << "lower scale size: " << low << endl;
+    VERBOSE_STR << "upper scale size: " << high << endl;
+    VERBOSE_STR << "phi value: " << phi << endl;
+  }
+  VERBOSE_STR << "temporal coherent: " << (temporal_coherent ? "yes" : "no" ) << endl;
+  VERBOSE_STR << "use border: " << (border>0.f ? "yes" : "no" ) << endl;
+  if( border>0.f )
+  {
+    VERBOSE_STR << "border width: " << border << endl;
   }
 
   while( true ) 
@@ -169,21 +185,19 @@
     // tone mapping
     int w = Y->getCols();
     int h = Y->getRows();
-    pfs::Array2DImpl* L = new pfs::Array2DImpl(w,h);
-
-    tmo_reinhard02( w, h, Y->getRawData(), L->getRawData(), use_scales, key, phi, num, low, high, temporal_coherent );
+    const pfstmo::Array2D ay(w, h, const_cast<float*>(Y->getRawData()));
+    pfstmo::Array2D al(w,h);
+    tmo_reinhard02( &ay, &al, use_scales, key, phi, num, low, high, temporal_coherent, border );
 
     for( int x=0 ; x<w ; x++ )
       for( int y=0 ; y<h ; y++ )
       {
-        float scale = (*L)(x,y) / (*Y)(x,y);
+        float scale = al(x,y) / ay(x,y);
         (*Y)(x,y) *= scale;
         (*X)(x,y) *= scale;
         (*Z)(x,y) *= scale;
       }
 
-    delete L;
-
     //---
     pfsio.writeFrame( frame, stdout );
     pfsio.freeFrame( frame );        
@@ -195,11 +209,19 @@
   try {
     pfstmo_reinhard02( argc, argv );
   }
-  catch( pfs::Exception ex ) {
-    fprintf( stderr, PROG_NAME " error: %s\n", ex.getMessage() );
+  catch (std::bad_alloc ex) {
+    fprintf(stderr, PROG_NAME " error: out of memory\n");
+    return EXIT_FAILURE;
+  }        
+  catch (std::exception ex) {
+    fprintf(stderr, PROG_NAME " error: %s\n", ex.what());
+    return EXIT_FAILURE;
+  }        
+  catch (pfs::Exception ex) {
+    fprintf(stderr, PROG_NAME " error: %s\n", ex.getMessage());
     return EXIT_FAILURE;
   }        
-  catch( QuietException  ex ) {
+  catch (QuietException  ex) {
     return EXIT_FAILURE;
   }        
   return EXIT_SUCCESS;
