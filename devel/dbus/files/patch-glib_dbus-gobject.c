--- glib/dbus-gobject.c.orig	Mon Apr  4 01:17:05 2005
+++ glib/dbus-gobject.c	Mon Apr  4 01:17:17 2005
@@ -396,8 +396,8 @@ write_interface (gpointer key, gpointer 
   for (; methods; methods = methods->next)
     {
       DBusGMethodInfo *method;
-      method = methods->data;
       const char *args;
+      method = methods->data;
 
       g_string_append_printf (xml, "    <method name=\"%s\">\n",
 			      method_name_from_object_info (object_info, method));
