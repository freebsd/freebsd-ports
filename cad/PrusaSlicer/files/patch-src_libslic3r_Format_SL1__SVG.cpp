--- src/libslic3r/Format/SL1_SVG.cpp.orig	2023-07-21 14:55:56 UTC
+++ src/libslic3r/Format/SL1_SVG.cpp
@@ -6,7 +6,8 @@
 #include "libslic3r/Format/ZipperArchiveImport.hpp"
 
 #define NANOSVG_IMPLEMENTATION
-#include "nanosvg/nanosvg.h"
+#define NANOSVGRAST_IMPLEMENTATION
+#include "libnanosvg/nanosvgrast.h"
 
 #include <limits>
 #include <cstdint>
