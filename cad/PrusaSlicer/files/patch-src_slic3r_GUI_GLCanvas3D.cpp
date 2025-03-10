--- src/slic3r/GUI/GLCanvas3D.cpp.orig	2025-02-20 18:44:48 UTC
+++ src/slic3r/GUI/GLCanvas3D.cpp
@@ -13,7 +13,7 @@
 
 #include <igl/unproject.h> // IWYU pragma: keep
 #include <LocalesUtils.hpp>
-#include <nanosvgrast.h>
+#include <libnanosvg/nanosvgrast.h>
 
 #include "libslic3r/BuildVolume.hpp"
 #include "libslic3r/ClipperUtils.hpp"
