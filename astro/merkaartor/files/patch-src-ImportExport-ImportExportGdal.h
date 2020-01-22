--- src/ImportExport/ImportExportGdal.h.orig	2015-07-19 14:50:09 UTC
+++ src/ImportExport/ImportExportGdal.h
@@ -19,7 +19,7 @@
 #include <gdal_priv.h>
 #include <gdal_version.h>
 
-#if GDAL_VERSION_MAJOR == 2
+#if GDAL_VERSION_MAJOR >= 2
 #define GDAL2
 #endif
 
