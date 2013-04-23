--- gui/about_dialog/about_dialog.cc.orig	2013-04-21 03:48:45.446269666 +0900
+++ gui/about_dialog/about_dialog.cc	2013-04-21 04:15:03.065269472 +0900
@@ -121,7 +121,11 @@
   SetLabelText(label_terms);
   SetLabelText(label_credits);
 
+#ifdef __FreeBSD__
+  product_image_.reset(new QImage("@@LOCALBASE@@/share/mozc-tool/icons/product_logo.png"));
+#else
   product_image_.reset(new QImage(":/product_logo.png"));
+#endif
 }
 
 void AboutDialog::paintEvent(QPaintEvent *event) {
