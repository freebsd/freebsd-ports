--- editor/tree/treeitemdelegate.cpp.orig	2025-01-17 04:44:02 UTC
+++ editor/tree/treeitemdelegate.cpp
@@ -30,6 +30,7 @@
 #include "basetypes.h"
 #include <QToolTip>
 #include <QHelpEvent>
+#include <QPainterPath>
 
 TreeItemDelegate::Icons * TreeItemDelegate::s_icons = nullptr;
 TreeItemDelegate::Colors * TreeItemDelegate::s_colors = nullptr;
