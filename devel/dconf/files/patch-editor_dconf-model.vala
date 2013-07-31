--- editor/dconf-model.vala.orig	2013-05-01 21:47:59.000000000 +0000
+++ editor/dconf-model.vala	2013-05-01 21:50:26.000000000 +0000
@@ -254,7 +254,7 @@
             string[] tokens = path.split("/", 2);
             string name = tokens[0];
 
-            Directory directory = get_child(name);
+            var directory = get_child(name);
             directory.load_schema(schema, tokens[1]);
         }
     }
@@ -341,8 +341,10 @@
         return (Key)iter.user_data;
     }
 
-    public bool get_iter(ref Gtk.TreeIter iter, Gtk.TreePath path)
+    public bool get_iter(out Gtk.TreeIter iter, Gtk.TreePath path)
     {
+        iter = Gtk.TreeIter();
+
         if (path.get_depth() != 1)
             return false;
 
@@ -391,11 +393,14 @@
         return true;
     }
 
-    public bool iter_children(ref Gtk.TreeIter iter, Gtk.TreeIter? parent)
+    public bool iter_children(out Gtk.TreeIter iter, Gtk.TreeIter? parent)
     {
+        iter = Gtk.TreeIter();
+
         if (parent != null || directory.keys.length() == 0)
             return false;
         set_iter(ref iter, directory.keys.nth_data(0));
+
         return true;
     }
 
@@ -412,8 +417,10 @@
             return 0;
     }
 
-    public bool iter_nth_child(ref Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
+    public bool iter_nth_child(out Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
     {
+        iter = Gtk.TreeIter();
+
         if (parent != null)
             return false;
 
@@ -423,8 +430,9 @@
         return true;
     }
 
-    public bool iter_parent(ref Gtk.TreeIter iter, Gtk.TreeIter child)
+    public bool iter_parent(out Gtk.TreeIter iter, Gtk.TreeIter child)
     {
+        iter = Gtk.TreeIter();
         return false;
     }
 
@@ -479,8 +487,10 @@
         return (SchemaValue)iter.user_data;
     }
 
-    public bool get_iter(ref Gtk.TreeIter iter, Gtk.TreePath path)
+    public bool get_iter(out Gtk.TreeIter iter, Gtk.TreePath path)
     {
+        iter = Gtk.TreeIter();
+
         if (path.get_depth() != 1)
             return false;
 
@@ -513,11 +523,15 @@
         return true;
     }
 
-    public bool iter_children(ref Gtk.TreeIter iter, Gtk.TreeIter? parent)
+    public bool iter_children(out Gtk.TreeIter iter, Gtk.TreeIter? parent)
     {
+        iter = Gtk.TreeIter();
+
         if (parent != null || schema_enum.values.length() == 0)
             return false;
+
         set_iter(ref iter, schema_enum.values.nth_data(0));
+
         return true;
     }
 
@@ -534,8 +548,10 @@
             return 0;
     }
 
-    public bool iter_nth_child(ref Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
+    public bool iter_nth_child(out Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
     {
+        iter = Gtk.TreeIter();
+
         if (parent != null)
             return false;
 
@@ -545,8 +561,9 @@
         return true;
     }
 
-    public bool iter_parent(ref Gtk.TreeIter iter, Gtk.TreeIter child)
+    public bool iter_parent(out Gtk.TreeIter iter, Gtk.TreeIter child)
     {
+        iter = Gtk.TreeIter();
         return false;
     }
 
@@ -586,9 +603,14 @@
         schemas = new SchemaList();
         try
         {
-            foreach (var dir in GLib.Environment.get_system_data_dirs())
+            var dirs = GLib.Environment.get_system_data_dirs();
+
+            /* Walk directories in reverse so the schemas in the
+             * directory which appears first in the XDG_DATA_DIRS are
+             * not overridden. */
+            for (int i = dirs.length - 1; i >= 0; i--)
             {
-                var path = Path.build_filename (dir, "glib-2.0", "schemas", null);
+                var path = Path.build_filename (dirs[i], "glib-2.0", "schemas");
                 if (File.new_for_path (path).query_exists ())
                     schemas.load_directory (path);
             }
@@ -601,7 +623,7 @@
         }
 
         /* Add keys for the values in the schemas */
-        foreach (var schema in schemas.schemas)
+        foreach (var schema in schemas.schemas.get_values())
             root.load_schema(schema, schema.path[1:schema.path.length]);
     }
 
@@ -639,8 +661,10 @@
             return (Directory)iter.user_data;
     }
 
-    public bool get_iter(ref Gtk.TreeIter iter, Gtk.TreePath path)
+    public bool get_iter(out Gtk.TreeIter iter, Gtk.TreePath path)
     {
+        iter = Gtk.TreeIter();
+
         if (!iter_nth_child(out iter, null, path.get_indices()[0]))
             return false;
 
@@ -672,19 +696,23 @@
 
     public bool iter_next(ref Gtk.TreeIter iter)
     {
-        Directory directory = get_directory(iter);
+        var directory = get_directory(iter);
         if (directory.index >= directory.parent.children.length() - 1)
             return false;
         set_iter(ref iter, directory.parent.children.nth_data(directory.index+1));
+
         return true;
     }
 
-    public bool iter_children(ref Gtk.TreeIter iter, Gtk.TreeIter? parent)
+    public bool iter_children(out Gtk.TreeIter iter, Gtk.TreeIter? parent)
     {
-        Directory directory = get_directory(parent);
+        iter = Gtk.TreeIter();
+
+        var directory = get_directory(parent);
         if (directory.children.length() == 0)
             return false;
         set_iter(ref iter, directory.children.nth_data(0));
+
         return true;
     }
 
@@ -698,21 +726,28 @@
         return (int) get_directory(iter).children.length();
     }
 
-    public bool iter_nth_child(ref Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
+    public bool iter_nth_child(out Gtk.TreeIter iter, Gtk.TreeIter? parent, int n)
     {
-        Directory directory = get_directory(parent);
+        iter = Gtk.TreeIter();
+
+        var directory = get_directory(parent);
         if (n >= directory.children.length())
             return false;
         set_iter(ref iter, directory.children.nth_data(n));
+
         return true;
     }
 
-    public bool iter_parent(ref Gtk.TreeIter iter, Gtk.TreeIter child)
+    public bool iter_parent(out Gtk.TreeIter iter, Gtk.TreeIter child)
     {
-        Directory directory = get_directory(child);
+        iter = Gtk.TreeIter();
+
+        var directory = get_directory(child);
         if (directory.parent == root)
             return false;
+
         set_iter(ref iter, directory.parent);
+
         return true;
     }
 
