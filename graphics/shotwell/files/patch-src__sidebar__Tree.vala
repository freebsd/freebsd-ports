--- src/sidebar/Tree.vala.orig
+++ src/sidebar/Tree.vala
@@ -545,7 +545,8 @@
         if (only_children)
             return;
         
-        store.remove(wrapper.get_iter());
+        Gtk.TreeIter iter = wrapper.get_iter();
+        store.remove(ref iter);
         
         if (selected_wrapper == wrapper)
             selected_wrapper = null;
@@ -637,7 +638,8 @@
         bool selected = (get_current_path().compare(wrapper.get_path()) == 0);
         
         // remove from current position in tree
-        store.remove(wrapper.get_iter());
+        Gtk.TreeIter iter = wrapper.get_iter();
+        store.remove(ref iter);
         
         Sidebar.Entry? parent = branch.get_parent(entry);
         assert(parent != null);
