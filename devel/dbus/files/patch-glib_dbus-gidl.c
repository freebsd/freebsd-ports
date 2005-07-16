--- glib/dbus-gidl.c.orig	Sat Jul  9 13:52:52 2005
+++ glib/dbus-gidl.c	Sat Jul 16 02:13:02 2005
@@ -662,8 +662,8 @@ property_info_unref (PropertyInfo *info)
   info->base.refcount -= 1;
   if (info->base.refcount == 0)
     {
-      base_info_free (info);
       g_free (info->type);
+      base_info_free (info);
     }
 }
 
@@ -722,8 +722,8 @@ arg_info_unref (ArgInfo *info)
   if (info->base.refcount == 0)
     {
       g_hash_table_destroy (info->annotations);
-      base_info_free (info);
       g_free (info->type);
+      base_info_free (info);
     }
 }
 
