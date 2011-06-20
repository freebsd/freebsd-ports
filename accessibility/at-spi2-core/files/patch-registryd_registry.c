--- registryd/registry.c.orig	2011-06-20 23:41:30.000000000 +0200
+++ registryd/registry.c	2011-06-20 23:57:26.000000000 +0200
@@ -348,7 +348,7 @@
   const char *member = dbus_message_get_member (message);
 
   if (type != DBUS_MESSAGE_TYPE_SIGNAL)
-    return;
+    return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
 
   if (!g_strcmp0(iface, DBUS_INTERFACE_DBUS) &&
       !g_strcmp0(member, "NameOwnerChanged"))
@@ -806,18 +806,18 @@
 
   if (!dbus_message_get_args (message, NULL, DBUS_TYPE_STRING, &orig_name,
     DBUS_TYPE_INVALID))
-    return;
+    return NULL;
 
   name = ensure_proper_format (orig_name);
 
   evdata = (event_data *) g_malloc (sizeof (*evdata));
   if (!evdata)
-    return;
+    return NULL;
   data = g_strsplit (name, ":", 3);
   if (!data)
     {
       g_free (evdata);
-      return;
+      return NULL;
     }
   if (!data [0])
     data [1] = NULL;
@@ -856,7 +856,7 @@
 
   if (!dbus_message_get_args (message, NULL, DBUS_TYPE_STRING, &orig_name,
     DBUS_TYPE_INVALID))
-    return;
+    return NULL;
   name = ensure_proper_format (orig_name);
 
   remove_events (registry, sender, name);
