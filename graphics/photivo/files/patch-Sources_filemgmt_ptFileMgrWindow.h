Fix build with Qt 5.11

--- Sources/filemgmt/ptFileMgrWindow.h.orig	2018-09-03 10:22:41 UTC
+++ Sources/filemgmt/ptFileMgrWindow.h
@@ -36,6 +36,7 @@
 #include "../ptConstants.h"
 #include "../ptReportOverlay.h"
 #include "../ptConstants.h"
+#include <QActionGroup>
 #include <QWidget>
 #include <QGraphicsScene>
 #include <memory>
