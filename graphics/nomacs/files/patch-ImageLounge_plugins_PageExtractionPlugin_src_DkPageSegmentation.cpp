--- ImageLounge/plugins/PageExtractionPlugin/src/DkPageSegmentation.cpp.orig	2020-05-30 09:28:31 UTC
+++ ImageLounge/plugins/PageExtractionPlugin/src/DkPageSegmentation.cpp
@@ -29,6 +29,7 @@
 #pragma warning(push, 0)	// no warnings from includes - begin
 #include <QDebug>
 #include <QPainter>
+#include <QPainterPath>
 
 #include <opencv2/imgproc/imgproc_c.h>
 #include <opencv2/imgproc/imgproc.hpp>
