--- ui/zenodesign/layertreeitemdelegate.cpp.orig	2023-11-22 19:17:26 UTC
+++ ui/zenodesign/layertreeitemdelegate.cpp
@@ -1,7 +1,7 @@
 #include "framework.h"
 #include "layerwidget.h"
 #include "layertreeitemdelegate.h"
-
+#include "zenostyle.h"
 
 LayerTreeitemDelegate::LayerTreeitemDelegate(QWidget* parent)
     : QStyledItemDelegate(parent), m_treeview(nullptr)
@@ -211,4 +211,4 @@ QSize LayerTreeitemDelegate::sizeHint(const QStyleOpti
 void LayerTreeitemDelegate::initStyleOption(QStyleOptionViewItem* option, const QModelIndex& index) const
 {
     QStyledItemDelegate::initStyleOption(option, index);
 }
+}
