--- gui/about_dialog/about_dialog.cc.org	2010-09-03 19:41:20.545071308 +0900
+++ gui/about_dialog/about_dialog.cc	2010-09-03 19:43:51.975348061 +0900
@@ -114,7 +114,7 @@
   SetLabelText(label_terms);
   SetLabelText(label_credits);
 
-  product_image_.reset(new QImage(":/product_logo.png"));
+  product_image_.reset(new QImage("@@LOCALBASE@@/share/mozc-tool/icons/product_logo.png"));
 }
 
 void AboutDialog::paintEvent(QPaintEvent *event) {
