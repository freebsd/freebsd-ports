--- filter/source/graphicfilter/iras/iras.cxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ filter/source/graphicfilter/iras/iras.cxx	2014-02-24 15:38:35.000000000 -0500
@@ -98,7 +98,7 @@
         return sal_False;
 
     maBmp = Bitmap( Size( mnWidth, mnHeight ), mnDstBitsPerPix );
-    if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == sal_False )
+    if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == 0 )
         return sal_False;
 
     if ( mnDstBitsPerPix <= 8 )     // paletten bildchen
