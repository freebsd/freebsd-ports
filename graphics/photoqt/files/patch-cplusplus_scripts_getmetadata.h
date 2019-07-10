--- cplusplus/scripts/getmetadata.h.orig	2019-07-07 08:22:25 UTC
+++ cplusplus/scripts/getmetadata.h
@@ -34,8 +34,7 @@
 #include "../logger.h"
 
 #ifdef EXIV2
-#include <exiv2/image.hpp>
-#include <exiv2/exif.hpp>
+#include <exiv2/exiv2.hpp>
 #endif
 
 class GetMetaData : public QObject {
