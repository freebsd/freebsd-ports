--- src/manglerintegration.h.orig	2010-08-05 02:56:16.000000000 +0200
+++ src/manglerintegration.h	2010-11-22 21:53:01.000000000 +0100
@@ -37,6 +37,15 @@
 # include <dbus/dbus-glib.h>
 # include <dbus/dbus-glib-lowlevel.h>
 #endif
+/* bad I know but dbus clashes with gdbus.
+ * These are defined in dbus and giomm with the same values.
+ */
+#undef DBUS_MESSAGE_TYPE_INVALID
+#undef DBUS_MESSAGE_TYPE_METHOD_CALL
+#undef DBUS_MESSAGE_TYPE_METHOD_RETURN
+#undef DBUS_MESSAGE_TYPE_ERROR
+#undef DBUS_MESSAGE_TYPE_SIGNAL
+
 #include <glib.h>
 #include <gtkmm.h>
 #include <string.h>
