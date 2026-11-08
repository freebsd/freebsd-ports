--- ui/zenoedit/viewport/viewportwidget.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/viewport/viewportwidget.h
@@ -3,6 +3,7 @@
 
 #include <QtWidgets>
 #include <QtOpenGL>
+#include <QOpenGLWidget>
 #include "common.h"
 #include "recordvideomgr.h"
 #include "dock/docktabcontent.h"
@@ -18,10 +19,10 @@ class ViewportWidget;
 class Picker;
 class CameraControl;
 
-class ViewportWidget : public QGLWidget
+class ViewportWidget : public QOpenGLWidget
 {
     Q_OBJECT
-    typedef QGLWidget _base;
+    typedef QOpenGLWidget _base;
 public:
     ViewportWidget(QWidget* parent = nullptr);
     ~ViewportWidget();
@@ -63,7 +64,7 @@ protected:
     void mouseReleaseEvent(QMouseEvent* event) override;
     void mouseMoveEvent(QMouseEvent* event) override;
     void mouseDoubleClickEvent(QMouseEvent* event) override;
-    void enterEvent(QEvent * event) override;
+    void enterEvent(QEnterEvent* event) override;
     void wheelEvent(QWheelEvent* event) override;
     void keyPressEvent(QKeyEvent* event) override;
     void keyReleaseEvent(QKeyEvent* event) override;
