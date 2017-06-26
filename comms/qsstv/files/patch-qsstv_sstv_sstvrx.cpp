--- qsstv/sstv/sstvrx.cpp.orig	2017-06-26 08:50:09.939282000 -0700
+++ qsstv/sstv/sstvrx.cpp	2017-06-26 08:50:22.482587000 -0700
@@ -35,6 +35,7 @@
 {
   syncFilterPtr=NULL;
   videoFilterPtr=NULL;
+  syncProcPtr=NULL;
 #ifndef QT_NO_DEBUG
   scopeViewerData=new scopeView("Data Scope");
   scopeViewerSyncNarrow=new scopeView("Sync Scope Narrow");
