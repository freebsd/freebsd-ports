--- ui/zenodesign/layertreeitemdelegate.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenodesign/layertreeitemdelegate.cpp
@@ -1,7 +1,7 @@
 #include "framework.h"
 #include "layerwidget.h"
 #include "layertreeitemdelegate.h"
-
+#include "zenostyle.h"
 
 LayerTreeitemDelegate::LayerTreeitemDelegate(QWidget* parent)
     : QStyledItemDelegate(parent), m_treeview(nullptr)
