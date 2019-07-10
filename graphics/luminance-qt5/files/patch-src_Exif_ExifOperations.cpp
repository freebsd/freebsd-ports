--- src/Exif/ExifOperations.cpp.orig	2019-07-07 08:28:28 UTC
+++ src/Exif/ExifOperations.cpp
@@ -34,7 +34,7 @@
 
 #include <boost/assign/list_of.hpp>
 
-#include <exif.hpp>
+#include <exiv2/exiv2.hpp>
 #include <image.hpp>
 
 #include "ExifOperations.h"
