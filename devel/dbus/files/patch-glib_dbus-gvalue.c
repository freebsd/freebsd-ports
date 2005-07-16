--- glib/dbus-gvalue.c.orig	Mon Jul 11 12:12:49 2005
+++ glib/dbus-gvalue.c	Sat Jul 16 02:15:19 2005
@@ -189,6 +189,10 @@ dbus_g_value_types_init (void)
 {
   static gboolean types_initialized;
 
+  static const DBusGTypeMarshalVtable basic_vtable = {
+    marshal_basic,
+    demarshal_basic
+  };
 
   if (types_initialized)
     return;
@@ -196,10 +200,6 @@ dbus_g_value_types_init (void)
   dbus_g_type_specialized_init ();
   dbus_g_type_specialized_builtins_init ();
   
-  static const DBusGTypeMarshalVtable basic_vtable = {
-    marshal_basic,
-    demarshal_basic
-  };
 
   /* Register basic types */
   {
