--- midimountain/glade_interface.cpp.orig	Mon Oct 29 10:42:25 2001
+++ midimountain/glade_interface.cpp	Sat Dec 15 13:59:02 2001
@@ -10,6 +10,7 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <string.h>
+#include <assert.h>
 
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtk.h>
@@ -17,6 +18,22 @@
 #include "glade_callbacks.h"
 #include "glade_interface.h"
 #include "../midimountain/glade_support.h"
+
+void    gtk_widget_add_accelerator	(GtkWidget           *widget,
+					const gchar		*accel_signal,
+					GtkAccelGroup		*accel_group,
+					guint			accel_key,
+					guint			accel_mods,
+					int			accel_flags)
+{
+	assert(0 <= accel_flags && accel_flags <= 8);
+	gtk_widget_add_accelerator(widget,
+				   accel_signal,
+				   accel_group,
+				   accel_key,
+				   accel_mods,
+				   (GtkAccelFlags)accel_flags);
+}
 
 GtkWidget*
 create_wndMain (void)
