--- digikam/utilities/imageeditor/imlibinterface.cpp.orig	Mon Jan 16 19:10:18 2006
+++ digikam/utilities/imageeditor/imlibinterface.cpp	Tue Apr 11 13:31:25 2006
@@ -21,14 +21,6 @@
 
 // Lib Tiff includes.
 
-extern "C" 
-{
-#include <tiffio.h>
-#include <sys/types.h>
-#include <sys/stat.h>
-#include <unistd.h>
-}
- 
 // C++ includes.
 
 #include <cmath>
@@ -36,6 +28,14 @@
 #include <cstdlib>
 #include <iostream>
 
+extern "C"
+{
+#include <tiffio.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
+}
+
 // Qt includes.
 
 #include <qstring.h>
@@ -203,7 +203,7 @@
     {
         return PNG_IMAGE;
     }
-    else if (rawFileParser.getCameraModel( QFile::encodeName(filePath), NULL, NULL) == 0)
+    else if (rawFileParser.getCameraModel( QFile::encodeName(filePath), (char *)NULL, (char *)NULL) == 0)
     {
         // RAW File test using dcraw.  
         // Need to test it before TIFF because any RAW file 
