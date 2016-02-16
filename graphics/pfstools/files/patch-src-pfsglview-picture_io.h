--- src/pfsglview/picture_io.h.orig	2008-07-29 16:14:30 UTC
+++ src/pfsglview/picture_io.h
@@ -6,7 +6,9 @@
 
 #define MAX_FRAMES_IN_MEMORY 10
 
-class pfs::Frame;
+namespace pfs {
+class Frame;
+};
 enum LumMappingMethod {
 			MAP_LINEAR,
 			MAP_GAMMA1_4,
