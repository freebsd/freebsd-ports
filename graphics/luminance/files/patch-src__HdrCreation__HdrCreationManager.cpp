--- ./src/HdrCreation/HdrCreationManager.cpp.orig	2010-05-20 21:46:40.000000000 +0400
+++ ./src/HdrCreation/HdrCreationManager.cpp	2010-11-12 14:20:53.448299319 +0300
@@ -23,6 +23,7 @@
 
 #include <QApplication>
 #include <QFileInfo>
+#include "../arch/freebsd/math.h"
 
 #include "Fileformat/pfstiff.h"
 #include "Exif/ExifOperations.h"
