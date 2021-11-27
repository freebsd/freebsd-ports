--- librawstudio/rs-exif.cc.orig	2011-02-15 17:28:05 UTC
+++ librawstudio/rs-exif.cc
@@ -21,6 +21,8 @@
 #include <iomanip>
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
+#include <exiv2/error.hpp>
+#include <exiv2/version.hpp>
 #include "rs-exif.h"
 #include <assert.h>
 #include "rs-library.h"
