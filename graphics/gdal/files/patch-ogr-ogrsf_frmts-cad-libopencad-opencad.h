Obtained from:	https://github.com/nextgis-borsch/lib_opencad/commit/f40ce46804f1612fbeb035d0be5a746105cfc17e

--- ogr/ogrsf_frmts/cad/libopencad/opencad.h.orig	2017-04-28 16:07:33 UTC
+++ ogr/ogrsf_frmts/cad/libopencad/opencad.h
@@ -31,10 +31,10 @@
 #ifndef OPENCAD_H
 #define OPENCAD_H
 
-#define OCAD_VERSION    "0.3.2"
+#define OCAD_VERSION    "0.3.3"
 #define OCAD_VERSION_MAJOR 0
 #define OCAD_VERSION_MINOR 3
-#define OCAD_VERSION_REV   2
+#define OCAD_VERSION_REV   3
 
 #ifndef OCAD_COMPUTE_VERSION
 #define OCAD_COMPUTE_VERSION(maj,min,rev) ((maj)*10000+(min)*100+rev) // maj - any, min < 99, rev < 99
