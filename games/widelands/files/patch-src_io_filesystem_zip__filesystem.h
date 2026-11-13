--- src/io/filesystem/zip_filesystem.h.orig	2026-02-17 15:34:33 UTC
+++ src/io/filesystem/zip_filesystem.h
@@ -21,8 +21,8 @@
 
 #include <memory>
 
-#include <unzip.h>
-#include <zip.h>
+#include <minizip/unzip.h>
+#include <minizip/zip.h>
 
 #include "io/filesystem/filesystem.h"
 #include "io/streamread.h"
