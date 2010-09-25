--- gui/about_dialog/about_dialog.cc.org	2010-09-25 11:06:33.059334293 +0900
+++ gui/about_dialog/about_dialog.cc	2010-09-25 11:07:21.090335160 +0900
@@ -113,8 +113,11 @@
 
   SetLabelText(label_terms);
   SetLabelText(label_credits);
-
+#ifdef __FreeBSD__
+  product_image_.reset(new QImage("@@LOCALBASE@@/share/mozc-tool/icons/product_logo.png"));
+#else
   product_image_.reset(new QImage(":/product_logo.png"));
+#endif
 }
 
 void AboutDialog::paintEvent(QPaintEvent *event) {
