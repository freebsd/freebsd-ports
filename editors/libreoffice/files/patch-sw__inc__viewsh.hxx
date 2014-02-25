--- sw/inc/viewsh.hxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ sw/inc/viewsh.hxx	2014-02-25 12:20:50.000000000 -0500
@@ -109,7 +109,7 @@
 
 
     // Set SwVisArea in order to enable clean formatting before printing.
-    friend void SetSwVisArea( ViewShell *pSh, const SwRect &, sal_Bool bPDFExport = sal_False );
+    friend void SetSwVisArea( ViewShell *pSh, const SwRect & );
 
     static BitmapEx*    mpReplaceBmp;    ///< replaced display of still loaded images
     static BitmapEx*    mpErrorBmp;      ///< error display of missed images
