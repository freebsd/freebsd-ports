--- midimountain/glade_interface.cpp.orig	Wed Apr 11 10:19:44 2001
+++ midimountain/glade_interface.cpp	Thu Apr 19 11:27:30 2001
@@ -10,6 +10,7 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <string.h>
+#include <assert.h>
 
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtk.h>
@@ -18,6 +19,22 @@
 #include "glade_interface.h"
 #include "glade_support.h"
 
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
+
 GtkWidget*
 create_wndMain (void)
 {
@@ -1788,7 +1805,7 @@
   gtk_box_pack_start (GTK_BOX (hboMainViewHeader), scrMainViewHeader, TRUE, TRUE, 0);
   gtk_widget_set_usize (scrMainViewHeader, 500, -2);
   gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrMainViewHeader), GTK_POLICY_NEVER, GTK_POLICY_NEVER);
-  gtk_range_set_update_policy (GTK_RANGE (GTK_SCROLLED_WINDOW (scrMainViewHeader)->hscrollbar), GTK_POLICY_AUTOMATIC);
+  gtk_range_set_update_policy (GTK_RANGE (GTK_SCROLLED_WINDOW (scrMainViewHeader)->hscrollbar), GtkUpdateType(GTK_POLICY_AUTOMATIC));
 
   vpoMainViewHeader = gtk_viewport_new (NULL, NULL);
   gtk_widget_set_name (vpoMainViewHeader, "vpoMainViewHeader");
@@ -2545,7 +2562,7 @@
   gtk_box_pack_end (GTK_BOX (hboViewController), cboPianoRollController, FALSE, FALSE, 0);
   gtk_widget_set_usize (cboPianoRollController, 230, -2);
   gtk_combo_set_value_in_list (GTK_COMBO (cboPianoRollController), TRUE, TRUE);
-  cboPianoRollController_items = g_list_append (cboPianoRollController_items, "");
+  cboPianoRollController_items = g_list_append (cboPianoRollController_items, (void*)"");
   gtk_combo_set_popdown_strings (GTK_COMBO (cboPianoRollController), cboPianoRollController_items);
   g_list_free (cboPianoRollController_items);
 
@@ -5534,14 +5551,14 @@
                     (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                     (GtkAttachOptions) (0), 0, 0);
   gtk_combo_set_use_arrows_always (GTK_COMBO (cboDenominator), TRUE);
-  cboDenominator_items = g_list_append (cboDenominator_items, "1");
-  cboDenominator_items = g_list_append (cboDenominator_items, "2");
-  cboDenominator_items = g_list_append (cboDenominator_items, "4");
-  cboDenominator_items = g_list_append (cboDenominator_items, "8");
-  cboDenominator_items = g_list_append (cboDenominator_items, "16");
-  cboDenominator_items = g_list_append (cboDenominator_items, "32");
-  cboDenominator_items = g_list_append (cboDenominator_items, "64");
-  cboDenominator_items = g_list_append (cboDenominator_items, "128");
+  cboDenominator_items = g_list_append (cboDenominator_items, (void*)"1");
+  cboDenominator_items = g_list_append (cboDenominator_items, (void*)"2");
+  cboDenominator_items = g_list_append (cboDenominator_items, (void*)"4");
+  cboDenominator_items = g_list_append (cboDenominator_items, (void*)"8");
+  cboDenominator_items = g_list_append (cboDenominator_items, (void*)"16");
+  cboDenominator_items = g_list_append (cboDenominator_items, (void*)"32");
+  cboDenominator_items = g_list_append (cboDenominator_items, (void*)"64");
+  cboDenominator_items = g_list_append (cboDenominator_items, (void*)"128");
   gtk_combo_set_popdown_strings (GTK_COMBO (cboDenominator), cboDenominator_items);
   g_list_free (cboDenominator_items);
 
