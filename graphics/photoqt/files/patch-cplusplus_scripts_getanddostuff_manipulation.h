--- cplusplus/scripts/getanddostuff/manipulation.h.orig	2019-07-07 08:24:57 UTC
+++ cplusplus/scripts/getanddostuff/manipulation.h
@@ -37,8 +37,7 @@
 #include "../../logger.h"
 
 #ifdef EXIV2
-#include <exiv2/image.hpp>
-#include <exiv2/exif.hpp>
+#include <exiv2/exiv2.hpp>
 #endif
 
 class GetAndDoStuffManipulation : public QObject {
