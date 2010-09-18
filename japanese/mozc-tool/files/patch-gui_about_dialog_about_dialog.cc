--- gui/about_dialog/about_dialog.cc.org	2010-09-18 12:44:49.983959188 +0900
+++ gui/about_dialog/about_dialog.cc	2010-09-18 12:46:24.679654311 +0900
@@ -114,7 +114,11 @@
   SetLabelText(label_terms);
   SetLabelText(label_credits);
 
+#ifdef __FreeBSD__
+  product_image_.reset(new QImage("@@LOCALBASE@@/share/mozc-tool/icons/product_logo.png"));
+#else
   product_image_.reset(new QImage(":/product_logo.png"));
+#endif
 }
 
 void AboutDialog::paintEvent(QPaintEvent *event) {
