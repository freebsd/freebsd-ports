--- src/hugin_base/panodata/SrcPanoImage.cpp.orig	2019-07-07 08:31:01 UTC
+++ src/hugin_base/panodata/SrcPanoImage.cpp
@@ -40,9 +40,7 @@
 #include <vigra/diff2d.hxx>
 #include <vigra/imageinfo.hxx>
 #include <hugin_utils/utils.h>
-#include <exiv2/exif.hpp>
-#include <exiv2/image.hpp>
-#include <exiv2/easyaccess.hpp>
+#include <exiv2/exiv2.hpp>
 #include <lensdb/LensDB.h>
 #include "Exiv2Helper.h"
 
