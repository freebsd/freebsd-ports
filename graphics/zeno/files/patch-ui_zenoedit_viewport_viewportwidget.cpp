--- ui/zenoedit/viewport/viewportwidget.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/viewport/viewportwidget.cpp
@@ -34,7 +34,7 @@ using std::unordered_map;
 
 
 ViewportWidget::ViewportWidget(QWidget* parent)
-    : QGLWidget(parent)
+    : QOpenGLWidget(parent)
     , m_camera(nullptr)
     , updateLightOnce(true)
     , m_pauseRenderDally(new QTimer)
@@ -47,11 +47,11 @@ ViewportWidget::ViewportWidget(QWidget*
     m_picker = std::make_shared<zeno::Picker>(this);
     m_fakeTrans = std::make_shared<zeno::FakeTransformer>(this);
 
-    QGLFormat fmt;
+    QSurfaceFormat fmt;
     int nsamples = 16;  // TODO: adjust in a zhouhang-panel
     fmt.setSamples(nsamples);
     fmt.setVersion(3, 2);
-    fmt.setProfile(QGLFormat::CoreProfile);
+    fmt.setProfile(QSurfaceFormat::CoreProfile);
     setFormat(fmt);
 
     // https://blog.csdn.net/zhujiangm/article/details/90760744
@@ -113,7 +113,9 @@ void ViewportWidget::setViewWidgetInfo(D
 
 void ViewportWidget::glDrawForCommandLine()
 {
-    QGLWidget::glDraw();
+    // QOpenGLWidget has no glDraw(), grabFramebuffer() renders the frame
+    // synchronously and, unlike repaint(), also when the window is hidden
+    grabFramebuffer();
 }
 
 ViewportWidget::~ViewportWidget()
@@ -144,9 +146,23 @@ void ViewportWidget::cleanUpView()
 
 namespace {
 struct OpenGLProcAddressHelper {
-    inline static QGLContext *ctx;
+    inline static QOpenGLContext *ctx;
+    inline static void (QOPENGLF_APIENTRYP bindFramebuffer)(GLenum target, GLuint framebuffer);
+
+    // QOpenGLWidget renders into its own framebuffer object instead of the
+    // window framebuffer, so binding framebuffer 0 in zenovis has to go to
+    // that object, the same way QOpenGLFunctions::glBindFramebuffer() does it
+    static void QOPENGLF_APIENTRY bindDefaultFramebuffer(GLenum target, GLuint framebuffer) {
+        if (framebuffer == 0)
+            framebuffer = QOpenGLContext::currentContext()->defaultFramebufferObject();
+        bindFramebuffer(target, framebuffer);
+    }
 
     static void *getProcAddress(const char *name) {
+        if (qstrcmp(name, "glBindFramebuffer") == 0) {
+            bindFramebuffer = reinterpret_cast<decltype(bindFramebuffer)>(ctx->getProcAddress(name));
+            return (void *)bindDefaultFramebuffer;
+        }
         return (void *)ctx->getProcAddress(name);
     }
 };
@@ -286,7 +302,7 @@ void ViewportWidget::wheelEvent(QWheelEv
 }
 
 void ViewportWidget::mouseReleaseEvent(QMouseEvent *event) {
-    if(event->button() == Qt::MidButton){
+    if(event->button() == Qt::MiddleButton){
         m_bMovingCamera = false;
     }
     _base::mouseReleaseEvent(event);
@@ -419,7 +435,7 @@ void ViewportWidget::keyReleaseEvent(QKe
     }
 }
 
-void ViewportWidget::enterEvent(QEvent *event) {
+void ViewportWidget::enterEvent(QEnterEvent* event) {
     setFocus();
     QWidget::enterEvent(event);
 }
