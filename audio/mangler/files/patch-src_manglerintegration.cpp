--- src/manglerintegration.cpp.orig	2010-11-22 21:27:26.000000000 +0100
+++ src/manglerintegration.cpp	2010-11-22 21:41:17.000000000 +0100
@@ -197,7 +197,7 @@
         return NULL;
     }
 
-    if (dbus_message_get_type(reply) != DBUS_MESSAGE_TYPE_METHOD_RETURN) {
+    if (dbus_message_get_type(reply) != Gio::DBUS_MESSAGE_TYPE_METHOD_RETURN) {
         dbus_message_unref (reply);
         return NULL;
     }
