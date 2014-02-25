--- filter/source/graphicfilter/ipcx/ipcx.cxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ filter/source/graphicfilter/ipcx/ipcx.cxx	2014-02-24 15:38:35.000000000 -0500
@@ -100,7 +100,7 @@
     if ( nStatus )
     {
         aBmp = Bitmap( Size( nWidth, nHeight ), nDestBitsPerPixel );
-        if ( ( pAcc = aBmp.AcquireWriteAccess() ) == sal_False )
+        if ( ( pAcc = aBmp.AcquireWriteAccess() ) == 0 )
             return sal_False;
 
         if ( nDestBitsPerPixel <= 8 )
