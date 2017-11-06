--- src/notewindow.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/notewindow.cpp
@@ -186,7 +186,7 @@ namespace gnote {
       return;
     }
     remove_accel_group(*parent);
-    if(parent->get_window() != 0
+    if(parent->get_window()
        && (parent->get_window()->get_state() & Gdk::WINDOW_STATE_MAXIMIZED) == 0) {
       int cur_width, cur_height;
       parent->get_size(cur_width, cur_height);
@@ -316,7 +316,7 @@ namespace gnote {
     }
     m_widget_actions[order] = action;
     m_signal_actions_changed();
-    if(Glib::RefPtr<NonModifyingNoteAction>::cast_dynamic(action) == 0) {
+    if(!Glib::RefPtr<NonModifyingNoteAction>::cast_dynamic(action)) {
       action->set_sensitive(m_enabled);
     }
   }
@@ -619,7 +619,7 @@ namespace gnote {
       m_global_keys->enabled(m_enabled);
     FOREACH(const Glib::RefPtr<Gtk::Action> & action, get_widget_actions()) {
       // A list includes empty actions to mark separators, non-modifying actions are always enabled
-      if(action != 0 && Glib::RefPtr<NonModifyingNoteAction>::cast_dynamic(action) == 0) {
+      if(action && !Glib::RefPtr<NonModifyingNoteAction>::cast_dynamic(action)) {
         action->set_sensitive(enable);
       }
     }
