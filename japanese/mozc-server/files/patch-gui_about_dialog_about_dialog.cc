--- gui/about_dialog/about_dialog.cc.orig	2011-12-04 16:22:26.291606976 +0900
+++ gui/about_dialog/about_dialog.cc	2011-12-04 16:44:21.340606780 +0900
@@ -119,7 +119,11 @@
   SetLabelText(label_terms);
   SetLabelText(label_credits);
 
+#ifdef __FreeBSD__
+  product_image_.reset(new QImage("@@LOCALBASE@@/share/mozc-tool/icons/product_logo.png"));
+#else
   product_image_.reset(new QImage(":/product_logo.png"));
+#endif
 }
 
 void AboutDialog::paintEvent(QPaintEvent *event) {
