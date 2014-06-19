--- graph_images.cpp.orig	2007-11-06 00:02:06.000000000 +0100
+++ graph_images.cpp	2007-11-06 00:02:21.000000000 +0100
@@ -22,7 +22,7 @@
 
 #include "defs.h"
 
-char *imageFiles[] = {
+const char *imageFiles[] = {
 	DATA_DIR PATHSEP "images" PATHSEP "arrow_d.bmp",
 	DATA_DIR PATHSEP "images" PATHSEP "arrow_l.bmp",
 	DATA_DIR PATHSEP "images" PATHSEP "arrow_r.bmp",
