--- subcommander/CommitItemLvi.cpp.orig	2008-07-13 20:40:21.000000000 +0900
+++ subcommander/CommitItemLvi.cpp	2012-05-10 05:39:57.000000000 +0900
@@ -32,7 +32,7 @@
 CommitItemLvi::CommitItemLvi( const svn::CommitItemPtr item,
   const QString& itemStr ) : super(), _item(item), _itemStr(itemStr)
 {
-  char* kinds[] =
+  const char* kinds[] =
   {
     _n("none"),
     _n("file"),
