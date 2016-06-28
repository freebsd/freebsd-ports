--- src/core/ziparchive.h.orig
+++ src/core/ziparchive.h
@@ -21,7 +21,7 @@
 
 #include <QtCore/QString>
 #include <QtCore/QStringList>
-#include "zlib/contrib/minizip/zip.h"
+#include <minizip/zip.h>
 
 class  ZipArchive
 {
