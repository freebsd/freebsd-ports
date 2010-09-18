--- gui/about_dialog/version_image_widget.cc.org	2010-09-18 12:47:08.097447075 +0900
+++ gui/about_dialog/version_image_widget.cc	2010-09-18 12:47:49.718581046 +0900
@@ -41,7 +41,11 @@
 void VersionImageWidget::loadImage() {
   // Currently the version is always latest.
   // TODO(mukai): add the version checking logic
+#ifdef __FreeBSD__
+  pixmap_.reset(new QPixmap("@@LOCALBASE@@/share/mozc-tool/icons/update_uptodate.png"));
+#else
   pixmap_.reset(new QPixmap(":/update_uptodate.png"));
+#endif
 }
 
 void VersionImageWidget::paintEvent(QPaintEvent* paint_event) {
