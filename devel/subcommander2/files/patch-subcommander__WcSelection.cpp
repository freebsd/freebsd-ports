--- subcommander/WcSelection.cpp.orig	2007-09-16 23:37:07.000000000 +0900
+++ subcommander/WcSelection.cpp	2012-05-10 05:43:53.000000000 +0900
@@ -89,8 +89,8 @@
 
   svn::WcStatusPtr status = *(_statuss.begin());
 
-  return !status->isAddable()
-    &&   status->isChanged()
+  return (!status->isAddable()
+    &&   status->isChanged())
     ||   status->isDir();
 }
 
