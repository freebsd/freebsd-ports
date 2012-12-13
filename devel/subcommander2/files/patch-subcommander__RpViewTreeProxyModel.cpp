--- subcommander/RpViewTreeProxyModel.cpp.orig	2008-08-09 15:55:24.000000000 +0900
+++ subcommander/RpViewTreeProxyModel.cpp	2012-05-10 05:52:30.000000000 +0900
@@ -28,7 +28,7 @@
 {
   QVariant value = sourceModel()->data( mapToSource(index), role );
 
-  if( index.column() == 0 && role == Qt::DisplayRole || role == Qt::EditRole )
+  if( (index.column() == 0 && role == Qt::DisplayRole) || role == Qt::EditRole )
   {
     QString temp = value.toString();
 
