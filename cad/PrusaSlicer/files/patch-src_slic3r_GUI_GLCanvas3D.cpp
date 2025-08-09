--- src/slic3r/GUI/GLCanvas3D.cpp.orig	2025-04-10 11:26:51 UTC
+++ src/slic3r/GUI/GLCanvas3D.cpp
@@ -18,7 +18,7 @@
 
 #include <igl/unproject.h> // IWYU pragma: keep
 #include <LocalesUtils.hpp>
-#include <nanosvgrast.h>
+#include <libnanosvg/nanosvgrast.h>
 
 #include "libslic3r/BuildVolume.hpp"
 #include "libslic3r/ClipperUtils.hpp"
