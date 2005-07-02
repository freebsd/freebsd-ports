--- glib/dbus-gvalue.c.orig	Sat Jul  2 01:08:35 2005
+++ glib/dbus-gvalue.c	Sat Jul  2 01:10:19 2005
@@ -213,15 +213,6 @@ dbus_g_value_types_init (void)
 {
   static gboolean types_initialized;
 
-
-  if (types_initialized)
-    return;
-
-  g_assert (sizeof (DBusGValueIterator) >= sizeof (DBusMessageIter));
-
-  dbus_g_type_specialized_init ();
-  dbus_g_type_specialized_builtins_init ();
-  
   static const DBusGTypeMarshalVtable basic_vtable = {
     marshal_basic,
     demarshal_basic
@@ -234,6 +225,15 @@ dbus_g_value_types_init (void)
     marshal_map,
     demarshal_ghashtable
   };
+
+  if (types_initialized)
+    return;
+
+  g_assert (sizeof (DBusGValueIterator) >= sizeof (DBusMessageIter));
+
+  dbus_g_type_specialized_init ();
+  dbus_g_type_specialized_builtins_init ();
+
 
   /* Register basic types */
   {
