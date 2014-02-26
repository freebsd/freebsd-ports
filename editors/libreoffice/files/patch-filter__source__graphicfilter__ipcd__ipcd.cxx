--- filter/source/graphicfilter/ipcd/ipcd.cxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ filter/source/graphicfilter/ipcd/ipcd.cxx	2014-02-24 15:38:35.000000000 -0500
@@ -151,7 +151,7 @@
             nBMPHeight = nWidth;
         }
         aBmp = Bitmap( Size( nBMPWidth, nBMPHeight ), 24 );
-        if ( ( mpAcc = aBmp.AcquireWriteAccess() ) == sal_False )
+        if ( ( mpAcc = aBmp.AcquireWriteAccess() ) == 0 )
             return sal_False;
 
         ReadImage( 5 ,65 );
