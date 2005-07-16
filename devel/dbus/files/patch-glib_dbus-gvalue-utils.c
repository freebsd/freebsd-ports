--- glib/dbus-gvalue-utils.c.orig	Mon Jul 11 00:54:18 2005
+++ glib/dbus-gvalue-utils.c	Sat Jul 16 17:27:30 2005
@@ -855,7 +855,6 @@
     NULL
   };
 
-  dbus_g_type_register_collection ("GArray", &array_vtable, 0);
 
   static const DBusGTypeSpecializedCollectionVtable ptrarray_vtable = {
     {
@@ -869,7 +868,6 @@
     NULL,
   };
 
-  dbus_g_type_register_collection ("GPtrArray", &ptrarray_vtable, 0);
 
   static const DBusGTypeSpecializedCollectionVtable slist_vtable = {
     {
@@ -883,8 +881,6 @@
     slist_end_append,
   };
 
-  dbus_g_type_register_collection ("GSList", &slist_vtable, 0);
-
   static const DBusGTypeSpecializedMapVtable hashtable_vtable = {
     {
       hashtable_constructor,
@@ -898,6 +894,9 @@
     hashtable_append
   };
 
+  dbus_g_type_register_collection ("GSList", &slist_vtable, 0);
+  dbus_g_type_register_collection ("GArray", &array_vtable, 0);
+  dbus_g_type_register_collection ("GPtrArray", &ptrarray_vtable, 0);
   dbus_g_type_register_map ("GHashTable", &hashtable_vtable, 0);
 }
 
