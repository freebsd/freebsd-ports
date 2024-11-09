--- src/libslic3r/Format/SVG.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/Format/SVG.cpp
@@ -7,7 +7,7 @@
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
 #include <boost/log/trivial.hpp>
-#include <nanosvg/nanosvg.h>
+#include <libnanosvg/nanosvg.h>
 #include <memory>
 #include <string>
 #include <utility>
