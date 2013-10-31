--- meshlab/mainwindow_RunTime.cpp.orig	2013-10-31 16:02:53.000000000 +0100
+++ meshlab/mainwindow_RunTime.cpp	2013-10-31 16:04:13.000000000 +0100
@@ -1575,7 +1575,9 @@
 
   /*********WARNING!!!!!! CHANGE IT!!! ALSO IN THE OPENPROJECT FUNCTION********/
   meshDoc()->setDocLabel(fileName);
-  mdiarea->activeSubWindow()->setWindowTitle(meshDoc()->docLabel());
+  if (mdiarea->activeSubWindow()) {
+      mdiarea->activeSubWindow()->setWindowTitle(meshDoc()->docLabel());
+  }
   layerDialog->setWindowTitle(meshDoc()->docLabel());
   /****************************************************************************/
 
