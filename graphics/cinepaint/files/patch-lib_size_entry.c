--- lib/size_entry.c.orig	2013-11-05 15:38:06.000000000 +0300
+++ lib/size_entry.c	2013-11-05 15:39:14.000000000 +0300
@@ -169,7 +169,7 @@
 GtkType
 gimp_size_entry_get_type (void)
 {
-  static guint gse_type = 0;
+  static GtkType gse_type = 0;
 
   if (!gse_type)
     {
