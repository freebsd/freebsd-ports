--- src/plugins/imageformats/jp2/qjp2handler.cpp.orig	2020-04-27 07:24:21 UTC
+++ src/plugins/imageformats/jp2/qjp2handler.cpp
@@ -44,6 +44,7 @@
 #include "qvariant.h"
 #include "qcolor.h"
 
+#include <math.h>
 #include <jasper/jasper.h>
 
 QT_BEGIN_NAMESPACE
