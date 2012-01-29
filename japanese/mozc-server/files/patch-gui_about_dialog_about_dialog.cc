--- gui/about_dialog/about_dialog.cc.orig	2012-01-29 13:42:31.223806652 +0900
+++ gui/about_dialog/about_dialog.cc	2012-01-29 13:49:18.542805785 +0900
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
