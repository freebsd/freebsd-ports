--- src/hugin1/hugin/RawImport.cpp.orig	2019-07-07 08:40:09 UTC
+++ src/hugin1/hugin/RawImport.cpp
@@ -35,10 +35,7 @@
 // workaround for a conflict between exiv2 and wxWidgets/CMake built
 #define HAVE_PID_T 1
 #endif
-#include <exiv2/exif.hpp>
-#include <exiv2/image.hpp>
-#include <exiv2/easyaccess.hpp>
-#include <exiv2/xmpsidecar.hpp>
+#include <exiv2/exiv2.hpp>
 #ifdef __WXMSW__
 #include <wx/msw/registry.h>
 #endif
