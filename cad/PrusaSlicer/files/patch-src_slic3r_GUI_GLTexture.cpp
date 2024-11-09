--- src/slic3r/GUI/GLTexture.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/slic3r/GUI/GLTexture.cpp
@@ -25,8 +25,8 @@
 #define STB_DXT_IMPLEMENTATION
 #include <stb_dxt.h>
 
-#include <nanosvg/nanosvg.h>
-#include <nanosvg/nanosvgrast.h>
+#include <libnanosvg/nanosvg.h>
+#include <libnanosvg/nanosvgrast.h>
 
 #include "libslic3r/Utils.hpp"
 
