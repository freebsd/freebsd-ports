--- digikam/utilities/imageeditor/imlibinterface.cpp.orig	Mon Jan 16 20:10:18 2006
+++ digikam/utilities/imageeditor/imlibinterface.cpp	Fri Jul 28 08:52:39 2006
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
@@ -293,7 +293,7 @@
             // -2 : 8bit ppm output
             // -w : Use camera white balance, if possible  
             // -a : Use automatic white balance
-            command  = "dcraw -c -2 -w -a -q 0 ";
+            command  = "dcraw -c -w -a -q 0 ";
             command += QFile::encodeName( KProcess::quote( filename ) );
             kdWarning() << "Running dcraw command : " << command << endl;
         
