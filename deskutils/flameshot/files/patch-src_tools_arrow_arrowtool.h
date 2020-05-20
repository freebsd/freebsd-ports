--- src/tools/arrow/arrowtool.h.orig	2020-05-20 03:53:57 UTC
+++ src/tools/arrow/arrowtool.h
@@ -19,6 +19,7 @@
 
 #include "src/tools/abstracttwopointtool.h"
 #include <QPainter>
+#include <QPainterPath>
 
 class ArrowTool : public AbstractTwoPointTool {
     Q_OBJECT
