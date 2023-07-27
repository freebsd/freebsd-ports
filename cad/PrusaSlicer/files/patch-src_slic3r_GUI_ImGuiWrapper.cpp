--- src/slic3r/GUI/ImGuiWrapper.cpp.orig	2023-07-25 16:14:00 UTC
+++ src/slic3r/GUI/ImGuiWrapper.cpp
@@ -35,8 +35,8 @@
 #include "GUI_App.hpp"
 
 #include "../Utils/MacDarkMode.hpp"
-#include <nanosvg/nanosvg.h>
-#include <nanosvg/nanosvgrast.h>
+#include "libnanosvg/nanosvg.h"
+#include "libnanosvg/nanosvgrast.h"
 
 // suggest location
 #include "libslic3r/ClipperUtils.hpp" // Slic3r::intersection
