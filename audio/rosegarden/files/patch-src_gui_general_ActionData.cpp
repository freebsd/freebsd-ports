--- src/gui/general/ActionData.cpp.orig	2022-11-12 19:53:19 UTC
+++ src/gui/general/ActionData.cpp
@@ -740,7 +740,7 @@ void ActionData::fillModel()
         m_model->setItem(0, 3, item);
         m_model->item(0, 3)->setEditable(false);
         if (ainfo.global) {
-            QVariant bg(QBrush(Qt::cyan));
+            QVariant bg{QBrush(Qt::cyan)};
             for (int col=0; col<8; col++) {
                 m_model->setData(m_model->index(0, col),
                                  bg, Qt::BackgroundRole);
