--- ext/native/image/png_load.cpp.orig	2015-09-06 20:37:59 UTC
+++ ext/native/image/png_load.cpp
@@ -5,7 +5,7 @@
 #ifdef USING_QT_UI
 #include <QtGui/QImage>
 #else
-#include "libpng17/png.h"
+#include "png.h"
 #endif
 
 #include "png_load.h"
