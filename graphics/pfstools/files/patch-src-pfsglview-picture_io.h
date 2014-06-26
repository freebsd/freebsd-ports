--- src/pfsglview/picture_io.h.orig	2008-07-29 16:14:30.000000000 +0000
+++ src/pfsglview/picture_io.h	2014-02-20 19:04:01.566588122 +0000
@@ -6,7 +6,9 @@
 
 #define MAX_FRAMES_IN_MEMORY 10
 
-class pfs::Frame;
+namespace pfs {
+class Frame;
+};
 enum LumMappingMethod {
 			MAP_LINEAR,
 			MAP_GAMMA1_4,
