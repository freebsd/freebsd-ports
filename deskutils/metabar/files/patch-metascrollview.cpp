--- src/metascrollview.cpp.orig	Sun Apr  3 23:03:42 2005
+++ src/metascrollview.cpp	Sun Apr  3 23:06:18 2005
@@ -43,7 +43,7 @@
   bool visible = verticalScrollBar()->isVisible();
 
   int w = width() - (visible ? verticalScrollBar()->width() : 0);
-  int h = (int)fmax(height(), metabarWidget->sizeHint().height());
+  int h = (height() > metabarWidget->sizeHint().height() ? height() : metabarWidget->sizeHint().height());
 
   QScrollView::resizeContents(w, h);
   
