--- source/theme/CarlaStyle.cpp.orig	2020-05-28 16:39:10 UTC
+++ source/theme/CarlaStyle.cpp
@@ -22,6 +22,7 @@
 
 #if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
 # include <QtGui/QPainter>
+# include <QtGui/QPainterPath>
 # include <QtGui/QPixmapCache>
 # include <QtWidgets/qdrawutil.h>
 # include <QtWidgets/QApplication>
