--- source/shared_lib/sources/graphics/PNGReader.cpp.orig	2012-05-03 20:07:04.000000000 +0200
+++ source/shared_lib/sources/graphics/PNGReader.cpp	2012-05-03 20:07:48.000000000 +0200
@@ -15,6 +15,7 @@
 #include "pixmap.h"
 #include <stdexcept>
 #include <png.h>
+#include <pngpriv.h>
 #include <setjmp.h>
 
 #include "leak_dumper.h"
