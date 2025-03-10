--- src/slic3r/GUI/IconManager.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/slic3r/GUI/IconManager.cpp
@@ -6,8 +6,8 @@
 #include <boost/nowide/cstdio.hpp>
 #include <boost/filesystem/operations.hpp>
 #include <boost/algorithm/string.hpp>
-#include "nanosvg/nanosvg.h"
-#include "nanosvg/nanosvgrast.h"
+#include <libnanosvg/nanosvg.h>
+#include <libnanosvg/nanosvgrast.h>
 #include "libslic3r/Utils.hpp" // ScopeGuard   
 
 #include "3DScene.hpp" // glsafe
