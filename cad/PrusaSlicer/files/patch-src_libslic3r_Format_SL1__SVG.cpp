--- src/libslic3r/Format/SL1_SVG.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/Format/SL1_SVG.cpp
@@ -28,7 +28,7 @@
 #include <utility>
 #include <cstddef>
 
-#include "nanosvg/nanosvg.h"
+#include <libnanosvg/nanosvgrast.h>
 
 namespace Slic3r {
 class SLAPrint;
