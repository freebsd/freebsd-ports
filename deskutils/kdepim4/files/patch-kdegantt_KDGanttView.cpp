--- kdgantt/KDGanttView.cpp.orig	Thu May  4 09:19:43 2006
+++ kdgantt/KDGanttView.cpp	Tue May  2 10:07:59 2006
@@ -323,7 +323,12 @@
   bool block = myTimeTable->blockUpdating();
   myTimeTable->setBlockUpdating( false );
   myTimeTable->updateMyContent();
-  qApp->processEvents();
+  /* The below causes recursive calls to various size updating methods, which
+   * cause QCanvas to hide and show items like mad, which is very slow. If
+   * there is a legitimate gui updating issue here somewhere, it will need
+   * to be solved differently.
+   */
+  //qApp->processEvents();
   int hintHeight = myTimeHeader->height();
   int legendHeight = 0;
   if ( showLegendButton() )
