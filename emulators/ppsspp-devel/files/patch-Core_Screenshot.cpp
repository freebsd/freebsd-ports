--- Core/Screenshot.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/Screenshot.cpp
@@ -18,7 +18,7 @@
 #ifdef USING_QT_UI
 #include <QtGui/QImage>
 #else
-#include <libpng17/png.h>
+#include "png.h"
 #include "ext/jpge/jpge.h"
 #endif
 
