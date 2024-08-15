--- ui/zenodesign/layerwidget.cpp.orig	2023-11-22 19:17:26 UTC
+++ ui/zenodesign/layerwidget.cpp
@@ -5,7 +5,7 @@
 #include "layertreeitemdelegate.h"
 #include "nodeswidget.h"
 #include "util.h"
-
+#include "zenostyle.h"
 
 NodesView* getCurrentView(QWidget* pWidget)
 {
