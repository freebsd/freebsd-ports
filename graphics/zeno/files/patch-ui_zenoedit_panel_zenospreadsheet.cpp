--- ui/zenoedit/panel/zenospreadsheet.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/panel/zenospreadsheet.cpp
@@ -197,7 +197,7 @@ ZenoSpreadsheet::ZenoSpreadsheet(QWidget
 
             node_sync.updateNodeInputString(new_node_location.value(), "key", prim_attr_view->model()->headerData(index, Qt::Vertical).toString().toStdString());
             const QModelIndex& idx = prim_attr_view->model()->index(index, 0);
-            const QStringList& vecLst = idx.data(Qt::DisplayRole).toString().split(",", QString::SkipEmptyParts);
+            const QStringList& vecLst = idx.data(Qt::DisplayRole).toString().split(",", Qt::SkipEmptyParts);
 
             zeno::zany object = dataModel->userDataByIndex(idx);
             if (zeno::objectIsLiterial<float>(object)) {
