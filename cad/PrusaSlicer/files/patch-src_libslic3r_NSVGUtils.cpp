--- src/libslic3r/NSVGUtils.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/NSVGUtils.cpp
@@ -5,7 +5,7 @@
 #include "NSVGUtils.hpp"
 
 #include <boost/nowide/fstream.hpp>
-#include <nanosvg/nanosvg.h>
+#include <libnanosvg/nanosvg.h>
 #include <array>
 #include <algorithm>
 #include <sstream>
