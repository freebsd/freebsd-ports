--- glib/dbus-gidl.c.orig	Fri Apr  8 22:38:35 2005
+++ glib/dbus-gidl.c	Fri Apr  8 22:37:53 2005
@@ -661,8 +661,8 @@ property_info_unref (PropertyInfo *info)
   info->base.refcount -= 1;
   if (info->base.refcount == 0)
     {
-      base_info_free (info);
       g_free (info->type);
+      base_info_free (info);
     }
 }
 
@@ -717,8 +717,8 @@ arg_info_unref (ArgInfo *info)
   info->base.refcount -= 1;
   if (info->base.refcount == 0)
     {
-      base_info_free (info);
       g_free (info->type);
+      base_info_free (info);
     }
 }
 const char*
