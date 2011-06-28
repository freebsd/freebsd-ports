--- gui/about_dialog/about_dialog.cc.org	2010-11-06 10:47:08.291193501 +0900
+++ gui/about_dialog/about_dialog.cc	2010-11-06 10:48:08.940188276 +0900
@@ -106,7 +106,11 @@
   SetLabelText(label_terms);
   SetLabelText(label_credits);
 
+#ifdef __FreeBSD__
+  product_image_.reset(new QImage("@@LOCALBASE@@/share/mozc-tool/icons/product_logo.png"));
+#else
   product_image_.reset(new QImage(":/product_logo.png"));
+#endif
 }
 
 void AboutDialog::paintEvent(QPaintEvent *event) {
