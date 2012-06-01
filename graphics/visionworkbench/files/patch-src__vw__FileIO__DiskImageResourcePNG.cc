--- src/vw/FileIO/DiskImageResourcePNG.cc.orig	2011-05-13 01:00:56.000000000 +0200
+++ src/vw/FileIO/DiskImageResourcePNG.cc	2012-05-05 08:28:48.000000000 +0200
@@ -24,6 +24,7 @@
 #include <vw/Image/Manipulation.h>
 
 #include <png.h>
+#include <zlib.h>
 #include <vector>
 #include <fstream>
 
