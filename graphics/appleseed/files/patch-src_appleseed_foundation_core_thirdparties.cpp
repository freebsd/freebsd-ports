--- src/appleseed/foundation/core/thirdparties.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed/foundation/core/thirdparties.cpp
@@ -42,7 +42,7 @@
 
 // IlmBase headers.
 #include "foundation/platform/_beginexrheaders.h"
-#include <OpenEXR/IlmBaseConfig.h>
+#include <Imath/ImathConfig.h>
 #include "foundation/platform/_endexrheaders.h"
 
 // LZ4 headers.
@@ -116,7 +116,7 @@ LibraryVersionArray ThirdParties::get_versions()
     }
 #endif
 
-    versions.push_back(APIStringPair("IlmBase", ILMBASE_VERSION_STRING));
+    versions.push_back(APIStringPair("Imath", IMATH_VERSION_STRING));
     versions.push_back(APIStringPair("libjpeg-turbo", LibJpegTurboVersion));
     versions.push_back(APIStringPair("LibTIFF", LibTIFFVersion));
     versions.push_back(APIStringPair("LZ4", format("{0}.{1}.{2}", LZ4_VERSION_MAJOR, LZ4_VERSION_MINOR, LZ4_VERSION_RELEASE)));
