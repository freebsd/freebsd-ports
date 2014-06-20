--- src/pfshdrcalibrate.cpp.orig	2007-03-28 13:29:43.000000000 +0000
+++ src/pfshdrcalibrate.cpp	2014-06-18 15:27:14.288956550 +0000
@@ -126,7 +126,7 @@
 
   int optionIndex = 0;
   while( 1 ) {
-    int c = getopt_long (argc, argv, "hvYFc:g:r:f:s:m:b:p:x", cmdLineOptions, &optionIndex);
+    int c = getopt_long (argc, argv, "hvYFc:g:r:f:s:m:b:p:xS:A:", cmdLineOptions, &optionIndex);
     if( c == -1 ) break;
     switch( c ) {
     case 'h':
@@ -192,7 +192,9 @@
       break;
     case 'p':
       mitsunaga_sample_no = (unsigned long)atoll(optarg);
-      if( opt_bpp<10 || opt_bpp>=(1 << 31))
+      if( mitsunaga_sample_no<10 )
+        throw pfs::Exception("too few samples");
+      if( mitsunaga_sample_no>=(1 << 31) )
         throw pfs::Exception("too many samples");
       break;	  
     case 'A':                   // max response
