--- src/preferences.c.orig	Thu Jun 21 12:24:14 2001
+++ src/preferences.c	Sat Apr 15 23:53:31 2006
@@ -631,10 +631,22 @@
         client, "/apps/yank/global/no_icons_in_tree", NULL);
     preferences.note_font = gconf_client_get_string(
         client, "/apps/yank/global/note_font", NULL);
+    if (preferences.note_font == "0") {
+	g_free(preferences.note_font);
+	preferences.note_font = NULL;
+    }
     preferences.note_tree_font = gconf_client_get_string(
         client, "/apps/yank/global/note_tree_font", NULL);
+    if (preferences.note_tree_font == "0") {
+	g_free(preferences.note_tree_font);
+	preferences.note_tree_font = NULL;
+    }
     preferences.todolist_font = gconf_client_get_string(
         client, "/apps/yank/global/todolist_font", NULL);
+    if (preferences.todolist_font == "0") {
+	g_free(preferences.todolist_font);
+	preferences.todolist_font = NULL;
+    }
     preferences.use_custom_font = gconf_client_get_int(
         client, "/apps/yank/global/use_custom_font", NULL);
     preferences.sorting_mode = gconf_client_get_int(
@@ -1468,11 +1480,14 @@
     {
         gnome_font_picker_set_font_name(GNOME_FONT_PICKER(b_note_fontp),
                                         preferences.note_font);
-    }
+    } else {
+		gnome_font_picker_set_font_name(GNOME_FONT_PICKER(b_note_fontp),
+										NULL);
+	}
     gnome_font_picker_set_title(GNOME_FONT_PICKER(b_note_fontp),
                                 _("Note font"));
-    gnome_font_picker_set_mode(GNOME_FONT_PICKER(b_note_fontp),
-                               GNOME_FONT_PICKER_MODE_FONT_INFO);
+//    gnome_font_picker_set_mode(GNOME_FONT_PICKER(b_note_fontp),
+//                               GNOME_FONT_PICKER_MODE_FONT_INFO);
     gtk_box_pack_start(GTK_BOX(hbox2), b_note_fontp, FALSE, TRUE, 0);
     
     hbox2 = gtk_hbox_new(FALSE, 4);
@@ -1486,11 +1501,14 @@
     {
         gnome_font_picker_set_font_name(GNOME_FONT_PICKER(b_note_tree_fontp),
                                         preferences.note_tree_font);
-    }
+    } else {
+		gnome_font_picker_set_font_name(GNOME_FONT_PICKER(b_note_tree_fontp),
+										NULL);
+	}
     gnome_font_picker_set_title(GNOME_FONT_PICKER(b_note_tree_fontp),
                                 _("NoteTree font"));
-    gnome_font_picker_set_mode(GNOME_FONT_PICKER(b_note_tree_fontp),
-                               GNOME_FONT_PICKER_MODE_FONT_INFO);
+//    gnome_font_picker_set_mode(GNOME_FONT_PICKER(b_note_tree_fontp),
+//                               GNOME_FONT_PICKER_MODE_FONT_INFO);
     gtk_box_pack_start(GTK_BOX(hbox2), b_note_tree_fontp, FALSE, TRUE, 0);
     
     hbox2 = gtk_hbox_new(FALSE, 4);
@@ -1504,11 +1522,14 @@
     {
         gnome_font_picker_set_font_name(GNOME_FONT_PICKER(b_todolist_fontp),
                                         preferences.todolist_font);
-    }
+    } else {
+        gnome_font_picker_set_font_name(GNOME_FONT_PICKER(b_todolist_fontp),
+				                        NULL);
+	}
     gnome_font_picker_set_title(GNOME_FONT_PICKER(b_todolist_fontp),
                                 _("Todolist font"));
-    gnome_font_picker_set_mode(GNOME_FONT_PICKER(b_todolist_fontp),
-                               GNOME_FONT_PICKER_MODE_FONT_INFO);
+//    gnome_font_picker_set_mode(GNOME_FONT_PICKER(b_todolist_fontp),
+//                               GNOME_FONT_PICKER_MODE_FONT_INFO);
     gtk_box_pack_start(GTK_BOX(hbox2), b_todolist_fontp, FALSE, TRUE, 0);
     
     gtk_widget_show_all(vbox);
