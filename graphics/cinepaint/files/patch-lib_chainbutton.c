--- lib/chainbutton.c.orig	2013-11-05 15:35:41.000000000 +0300
+++ lib/chainbutton.c	2013-11-05 15:36:17.000000000 +0300
@@ -155,7 +155,7 @@
 GtkType
 gimp_chain_button_get_type (void)
 {
-  static guint gcb_type = 0;
+  static GtkType gcb_type = 0;
 
   if (!gcb_type)
     {
