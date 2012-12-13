--- subcommander/WcViewTreeProxyModel.cpp.orig	2009-01-18 18:57:43.000000000 +0900
+++ subcommander/WcViewTreeProxyModel.cpp	2012-05-10 05:44:52.000000000 +0900
@@ -33,7 +33,7 @@
 {
   QVariant value = sourceModel()->data( mapToSource(index), role );
 
-  if( index.column() == 0 && role == Qt::DisplayRole || role == Qt::EditRole )
+  if( (index.column() == 0 && role == Qt::DisplayRole) || role == Qt::EditRole )
   {
     QString temp = value.toString();
 
