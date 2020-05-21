--- editor/tree/treeitemdelegate.cpp.orig	2020-05-21 08:02:47 UTC
+++ editor/tree/treeitemdelegate.cpp
@@ -29,6 +29,7 @@
 #include "basetypes.h"
 #include <QToolTip>
 #include <QHelpEvent>
+#include <QPainterPath>
 
 TreeItemDelegate::Icons * TreeItemDelegate::s_icons = nullptr;
 TreeItemDelegate::Colors * TreeItemDelegate::s_colors = nullptr;
