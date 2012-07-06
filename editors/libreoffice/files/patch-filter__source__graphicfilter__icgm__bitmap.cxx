--- filter/source/graphicfilter/icgm/bitmap.cxx.orig	2012-07-06 12:01:36.000000000 +0200
+++ filter/source/graphicfilter/icgm/bitmap.cxx	2012-07-06 12:02:30.000000000 +0200
@@ -254,9 +254,9 @@
     rDesc.mnY = mpCGM->ImplGetUI( nPrecision );
     rDesc.mnLocalColorPrecision = mpCGM->ImplGetI( nPrecision );
     rDesc.mnScanSize = 0;
-    switch( rDesc.mnLocalColorPrecision )
+    switch( (int) rDesc.mnLocalColorPrecision )
     {
-        case 0x80000001 :                       // monochrome ( bit = 0->backgroundcolor )
+        case -0x7FFFFFFF :                      // monochrome ( bit = 0->backgroundcolor )
         case 0 :                                //              bit = 1->fillcolor
             rDesc.mnDstBitsPerPixel = 1;
             break;
