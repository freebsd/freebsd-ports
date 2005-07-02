--- glib/dbus-gvalue-utils.c.orig	Sat Jul  2 01:10:40 2005
+++ glib/dbus-gvalue-utils.c	Sat Jul  2 01:11:18 2005
@@ -682,7 +682,6 @@ dbus_g_type_specialized_builtins_init (v
     NULL
   };
 
-  dbus_g_type_register_collection ("GArray", &array_vtable, 0);
 
   static const DBusGTypeSpecializedCollectionVtable ptrarray_vtable = {
     {
@@ -697,7 +696,6 @@ dbus_g_type_specialized_builtins_init (v
     ptrarray_iterator
   };
 
-  dbus_g_type_register_collection ("GPtrArray", &ptrarray_vtable, 0);
 
   static const DBusGTypeSpecializedMapVtable hashtable_vtable = {
     {
@@ -711,5 +709,7 @@ dbus_g_type_specialized_builtins_init (v
     hashtable_iterator
   };
 
+  dbus_g_type_register_collection ("GArray", &array_vtable, 0);
+  dbus_g_type_register_collection ("GPtrArray", &ptrarray_vtable, 0);
   dbus_g_type_register_map ("GHashTable", &hashtable_vtable, 0);
 }
