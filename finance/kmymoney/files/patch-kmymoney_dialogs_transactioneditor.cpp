Fix crash when adding a new schedule to scheduled transactions

--- kmymoney/dialogs/transactioneditor.cpp.orig	2018-04-17 02:57:53 UTC
+++ kmymoney/dialogs/transactioneditor.cpp
@@ -178,7 +178,7 @@ void TransactionEditor::setup(QWidgetList& tabOrderWid
 
   // remove all unused widgets and don't forget to remove them
   // from the tab order list as well
-  d->m_editWidgets.removeOrphans();
+  // d->m_editWidgets.removeOrphans();
   QWidgetList::iterator it_w;
   const QWidgetList editWidgets(d->m_editWidgets.values());
   for (it_w = tabOrderWidgets.begin(); it_w != tabOrderWidgets.end();) {
