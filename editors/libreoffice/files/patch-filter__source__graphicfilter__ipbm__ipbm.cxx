--- filter/source/graphicfilter/ipbm/ipbm.cxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ filter/source/graphicfilter/ipbm/ipbm.cxx	2014-02-24 15:38:35.000000000 -0500
@@ -102,7 +102,7 @@
     {
         case 0 :
             maBmp = Bitmap( Size( mnWidth, mnHeight ), 1 );
-            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == sal_False )
+            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == 0 )
                 return sal_False;
             mpAcc->SetPaletteEntryCount( 2 );
             mpAcc->SetPaletteColor( 0, BitmapColor( 0xff, 0xff, 0xff ) );
@@ -117,7 +117,7 @@
             else
                 maBmp = Bitmap( Size( mnWidth, mnHeight ), 8);
 
-            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == sal_False )
+            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == 0 )
                 return sal_False;
             mnCol = (sal_uInt16)mnMaxVal + 1;
             if ( mnCol > 256 )
@@ -132,7 +132,7 @@
             break;
         case 2 :
             maBmp = Bitmap( Size( mnWidth, mnHeight ), 24 );
-            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == sal_False )
+            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == 0 )
                 return sal_False;
             break;
     }
