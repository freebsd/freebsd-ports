--- app/depth/channel.c.orig	2013-11-05 11:22:13.000000000 +0300
+++ app/depth/channel.c	2013-11-05 11:27:06.000000000 +0300
@@ -51,10 +51,9 @@
 static GimpDrawableClass *parent_class = NULL;
 
 
-guint
-gimp_channel_get_type ()
+GtkType gimp_channel_get_type ()
 {
-  static guint channel_type = 0;
+  static GtkType channel_type = 0;
 
   if (!channel_type)
     {
