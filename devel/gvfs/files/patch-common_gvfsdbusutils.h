https://bugzilla.gnome.org/show_bug.cgi?id=722411

--- common/gvfsdbusutils.h.orig	2014-05-25 17:43:08.000000000 +0200
+++ common/gvfsdbusutils.h	2014-05-25 17:43:08.000000000 +0200
@@ -0,0 +1,42 @@
+/* GIO - GLib Input, Output and Streaming Library
+ * 
+ * Copyright (C) 2006-2007 Red Hat, Inc.
+ *
+ * This library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2 of the License, or (at your option) any later version.
+ *
+ * This library is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General
+ * Public License along with this library; if not, write to the
+ * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
+ * Boston, MA 02110-1301, USA.
+ *
+ * Author: Alexander Larsson <alexl@redhat.com>
+ */
+
+#ifndef __GVFS_DBUS_UTILS_H__
+#define __GVFS_DBUS_UTILS_H__
+
+#include <glib.h>
+#include <dbus/dbus.h>
+#include <gio/gio.h>
+
+G_BEGIN_DECLS
+
+typedef gboolean (*GFDSourceFunc) (gpointer data,
+				   GIOCondition condition,
+				   int fd);
+
+void         _g_dbus_connection_integrate_with_main (DBusConnection   *connection);
+void         _g_dbus_connection_remove_from_main    (DBusConnection   *connection);
+
+G_END_DECLS
+
+
+#endif /* __GVFS_DBUS_UTILS_H__ */
