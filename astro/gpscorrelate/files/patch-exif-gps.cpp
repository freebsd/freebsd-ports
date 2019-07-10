--- exif-gps.cpp.orig	2019-07-07 08:26:16 UTC
+++ exif-gps.cpp
@@ -40,9 +40,7 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
-
-#include "exiv2/image.hpp"
-#include "exiv2/exif.hpp"
+#include <exiv2/exiv2.hpp>
 
 #include "gpsstructure.h"
 #include "exif-gps.h"
