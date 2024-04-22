--- src/slic3r/GUI/GLTexture.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/GLTexture.cpp
@@ -25,8 +25,8 @@
 #define STB_DXT_IMPLEMENTATION
 #include "stb_dxt/stb_dxt.h"
 
-#include <nanosvg/nanosvg.h>
-#include <nanosvg/nanosvgrast.h>
+#include "libnanosvg/nanosvg.h"
+#include "libnanosvg/nanosvgrast.h"
 
 #include "libslic3r/Utils.hpp"
 
