--- ui/zenoedit/dialog/zmathpresetsubgrapdlg.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/dialog/zmathpresetsubgrapdlg.cpp
@@ -80,12 +80,12 @@ void ZMatchPresetSubgraphDlg::onRowInser
     {
         QWidget* pWidget = new QWidget(this);
         QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
-        pLayout->setMargin(0);
+        pLayout->setContentsMargins(0, 0, 0, 0);
         QString param = idx.data(Qt::DisplayRole).toString();
         pLayout->addStretch();
 
         ZComboBox* pComboBox = new ZComboBox(this);
-        QList<QString> lst = parent.data(Qt::UserRole).value<QSet<QString> >().toList();
+        QList<QString> lst = parent.data(Qt::UserRole).value<QSet<QString> >().values();
         lst.prepend(param);
         pComboBox->addItems(lst);
         pComboBox->setCurrentText(param);
