--- src/core/ziparchive.cc.orig
+++ src/core/ziparchive.cc
@@ -23,7 +23,7 @@
 
 #include "defs.h"
 #include "src/core/logging.h"
-#include "zlib/contrib/minizip/zip.h"
+#include <minizip/zip.h>
 
 #include <QtCore/QFile>
 #include <QtCore/QDebug>
