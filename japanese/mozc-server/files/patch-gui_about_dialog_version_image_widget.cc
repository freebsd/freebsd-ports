--- gui/about_dialog/version_image_widget.cc.org	2010-09-03 19:45:25.423577654 +0900
+++ gui/about_dialog/version_image_widget.cc	2010-09-03 19:44:57.400714134 +0900
@@ -41,7 +41,7 @@
 void VersionImageWidget::loadImage() {
   // Currently the version is always latest.
   // TODO(mukai): add the version checking logic
-  pixmap_.reset(new QPixmap(":/update_uptodate.png"));
+  pixmap_.reset(new QPixmap("@@LOCALBASE@@/share/mozc-tool/icons/update_uptodate.png"));
 }
 
 void VersionImageWidget::paintEvent(QPaintEvent* paint_event) {
