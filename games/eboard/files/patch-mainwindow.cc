
$FreeBSD$

--- mainwindow.cc.orig	Fri Jun 28 03:33:05 2002
+++ mainwindow.cc	Sat Sep 28 23:00:58 2002
@@ -997,7 +997,7 @@
   }
 }
 
-void MainWindow::openEngine(EngineProtocol *xpp, EngineBookmark *ebm=0) {
+void MainWindow::openEngine(EngineProtocol *xpp, EngineBookmark *ebm) {
   int i;
   global.debug("MainWindow","openEngine");
   disconnect();
