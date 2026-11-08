--- studio/include/studio/view.hpp.orig	2025-11-12 13:52:17 UTC
+++ studio/include/studio/view.hpp
@@ -110,7 +110,7 @@ protected slots:
     void varsDragged(QMap<libfive::Tree::Id, float> vs);
 
 protected slots:
-    void update() { QOpenGLWidget::update(); }
+    void update() { QWidget::update(); }
     void redrawPicker();
 
 protected:
