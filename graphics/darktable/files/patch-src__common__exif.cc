--- ./src/common/exif.cc.orig	2010-12-07 12:49:56.000000000 +0100
+++ ./src/common/exif.cc	2011-04-11 14:54:09.176904295 +0200
@@ -29,11 +29,8 @@
 #include "common/imageio.h"
 }
 // #include <libexif/exif-data.h>
-#include <exiv2/xmp.hpp>
-#include <exiv2/error.hpp>
-#include <exiv2/image.hpp>
-#include <exiv2/exif.hpp>
 #include <exiv2/canonmn.hpp>
+#include <exiv2/exiv2.hpp>
 #include <sqlite3.h>
 #include <iostream>
 #include <fstream>
