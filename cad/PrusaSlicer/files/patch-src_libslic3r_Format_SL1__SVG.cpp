--- src/libslic3r/Format/SL1_SVG.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/libslic3r/Format/SL1_SVG.cpp
@@ -10,7 +10,8 @@
 #include "libslic3r/Format/ZipperArchiveImport.hpp"
 
 #define NANOSVG_IMPLEMENTATION
-#include "nanosvg/nanosvg.h"
+#define NANOSVGRAST_IMPLEMENTATION
+#include "libnanosvg/nanosvgrast.h"
 
 #include <limits>
 #include <cstdint>
