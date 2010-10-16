--- gui/about_dialog/about_dialog.cc.org	2010-10-16 11:59:20.527184356 +0900
+++ gui/about_dialog/about_dialog.cc	2010-10-16 11:59:55.382185760 +0900
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
