--- plugins/meta-exiv2/exiv2-metadata.cpp.orig	2011-02-26 23:13:39 UTC
+++ plugins/meta-exiv2/exiv2-metadata.cpp
@@ -22,6 +22,8 @@
 #include <iomanip>
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
+#include <exiv2/version.hpp>
+#include <exiv2/error.hpp>
 #include <assert.h>
 #include "exiv2-metadata.h"
 #include <math.h>
