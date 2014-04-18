--- ./src/editor/editorview.cpp.orig	2014-03-29 12:42:23.000000000 +0000
+++ ./src/editor/editorview.cpp	2014-04-06 15:45:53.624369553 +0000
@@ -240,7 +240,7 @@
 
             if (MainWindow::instance()->randomlyRotateObjects())
             {
-                object.setRotation(std::rand() % 360);
+                object.setRotation(rand() % 360);
             }
 
             scene()->addItem(&object);
