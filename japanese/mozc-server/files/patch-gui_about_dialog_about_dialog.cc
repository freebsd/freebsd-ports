--- gui/about_dialog/about_dialog.cc.orig	2013-03-29 13:33:58.000000000 +0900
+++ gui/about_dialog/about_dialog.cc	2013-04-27 15:16:49.000000000 +0900
@@ -121,7 +121,11 @@
   SetLabelText(label_terms);
   SetLabelText(label_credits);
 
+#ifdef OS_FREEBSD
+  product_image_.reset(new QImage(LOCALBASE "/share/mozc-tool/icons/product_logo.png"));
+#else
   product_image_.reset(new QImage(":/product_logo.png"));
+#endif
 }
 
 void AboutDialog::paintEvent(QPaintEvent *event) {
