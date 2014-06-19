--- app/channel.h.orig	2013-11-05 11:20:03.000000000 +0300
+++ app/channel.h	2013-11-05 11:20:52.000000000 +0300
@@ -39,7 +39,7 @@
 #define GIMP_CHANNEL_CLASS(klass) GTK_CHECK_CLASS_CAST (klass, gimp_channel_get_type(), GimpChannelClass)
 #define GIMP_IS_CHANNEL(obj)     GTK_CHECK_TYPE (obj, gimp_channel_get_type())
 
-guint gimp_channel_get_type (void);
+GtkType gimp_channel_get_type (void);
 
 /*  Special undo type  */
 typedef struct ChannelUndo ChannelUndo;
