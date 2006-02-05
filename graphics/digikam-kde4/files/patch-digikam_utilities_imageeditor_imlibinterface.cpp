--- digikam/utilities/imageeditor/imlibinterface.cpp.orig	Mon Jan 23 22:31:31 2006
+++ digikam/utilities/imageeditor/imlibinterface.cpp	Mon Jan 23 22:32:01 2006
@@ -203,7 +203,7 @@
     {
         return PNG_IMAGE;
     }
-    else if (rawFileParser.getCameraModel( QFile::encodeName(filePath), NULL, NULL) == 0)
+    else if (rawFileParser.getCameraModel( QFile::encodeName(filePath), (char *)NULL, (char *)NULL) == 0)
     {
         // RAW File test using dcraw.  
         // Need to test it before TIFF because any RAW file 
