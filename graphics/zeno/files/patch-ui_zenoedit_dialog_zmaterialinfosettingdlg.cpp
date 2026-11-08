--- ui/zenoedit/dialog/zmaterialinfosettingdlg.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/dialog/zmaterialinfosettingdlg.cpp
@@ -220,13 +220,13 @@ void ZMaterialInfoSettingDlg::updateMatc
             pItem->appendRow(pChildItem);
             pChildItem->setData(paramName, Qt::UserRole);
             ZComboBox* pComboBox = new ZComboBox(this);
-            QList<QString> lst = map[name].toList();
+            QList<QString> lst = map[name].values();
             lst.prepend(paramName);
             pComboBox->addItems(lst);
             pComboBox->setCurrentText(paramName);
             QWidget* pWidget = new QWidget(this);
             QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
-            pLayout->setMargin(0);
+            pLayout->setContentsMargins(0, 0, 0, 0);
             pLayout->addStretch();
             pLayout->addWidget(pComboBox);
             ui->m_matchTreeView->setIndexWidget(pChildItem->index(), pWidget);
@@ -294,10 +294,10 @@ void ZMaterialInfoSettingDlg::onOKClicke
         int row1 = 0;
 
         QJsonObject obj;
-        while (parent.child(row1, 0).isValid())
+        while (m_pModel->index(row1, 0, parent).isValid())
         {
-            QString text = parent.child(row1, 0).data(Qt::UserRole).toString();
-            QString jsonKey = parent.child(row1, 0).data().toString();
+            QString text = m_pModel->index(row1, 0, parent).data(Qt::UserRole).toString();
+            QString jsonKey = m_pModel->index(row1, 0, parent).data().toString();
             obj[jsonKey] = text;
             row1++;
         }
