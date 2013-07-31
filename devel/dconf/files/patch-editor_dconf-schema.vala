--- editor/dconf-schema.vala.orig	2013-05-01 21:48:04.000000000 +0000
+++ editor/dconf-schema.vala	2013-05-01 21:50:26.000000000 +0000
@@ -44,7 +44,7 @@
             {
                 try
                 {
-                    default_value = Variant.parse(new VariantType(type), child->children->content);
+                    default_value = Variant.parse(new VariantType(type), child->get_content());
                 }
                 catch (VariantParseError e)
                 {
@@ -52,9 +52,9 @@
                 }
             }
             else if (child->name == "summary")
-                summary = child->children == null ? "" : child->children->content;
+                summary = child->get_content();
             else if (child->name == "description")
-                description = child->children == null ? "" : child->children->content;
+                description = child->get_content();
             else if (child->name == "range")
                 range = new SchemaValueRange.from_xml(type, child);
             else if (child->name == "choices")
@@ -345,7 +345,7 @@
 
 public class SchemaList
 {
-    public GLib.List<Schema> schemas = new GLib.List<Schema>();
+    public GLib.HashTable<string, Schema> schemas = new GLib.HashTable<string, Schema>(str_hash, str_equal);
     public GLib.HashTable<string, SchemaKey> keys = new GLib.HashTable<string, SchemaKey>(str_hash, str_equal);
     public GLib.HashTable<string, SchemaEnum> enums = new GLib.HashTable<string, SchemaEnum>(str_hash, str_equal);
     public GLib.HashTable<string, SchemaFlags> flags = new GLib.HashTable<string, SchemaFlags>(str_hash, str_equal);
@@ -385,7 +385,7 @@
                     string full_name = schema.path + key.name;
                     keys.insert(full_name, key);
                 }
-                schemas.append(schema);
+                schemas.insert(schema.id, schema);
             }
             else if (node->name == "enum")
             {
@@ -407,19 +407,79 @@
         delete doc;
     }
 
+    public void parse_override(string path)
+    {
+        var keyfile = new KeyFile();
+        try
+        {
+            keyfile.load_from_file(path, KeyFileFlags.NONE);
+        }
+        catch (Error e)
+        {
+            warning("Failed to load override file %s: %s", path, e.message);
+            return;
+        }
+
+        foreach (var group in keyfile.get_groups())
+        {
+            var schema = schemas.lookup(group);
+            if (schema == null)
+                continue;
+
+            string[] keys;
+            try { keys = keyfile.get_keys(group); } catch (Error e) { continue; }
+
+            foreach (var key_name in keys)
+            {
+                string value;
+                try { value = keyfile.get_value(group, key_name); } catch (Error e) { continue; }
+
+                var key = schema.keys.lookup (key_name);
+                if (key == null)
+                    continue;
+
+                Variant default_value;
+                try
+                {
+                    default_value = Variant.parse(new VariantType(key.type), value);
+                }
+                catch (VariantParseError e)
+                {
+                    // ...
+                    continue;
+                }
+
+                key.default_value = default_value;
+            }
+        }
+    }
+
     public void load_directory(string dir) throws Error
     {
-        File directory = File.new_for_path(dir);
+        var directory = File.new_for_path(dir);
+
         var i = directory.enumerate_children (FileAttribute.STANDARD_NAME, 0, null);
-        FileInfo info;
-        while ((info = i.next_file (null)) != null) {
-            string name = info.get_name();
+        while (true)
+        {
+            var info = i.next_file (null);
+            if (info == null)
+                break;
+            var name = info.get_name();
 
-            if (!name.has_suffix(".gschema.xml") && !name.has_suffix(".enums.xml"))
-                continue;
+            if (name.has_suffix(".gschema.xml") || name.has_suffix(".enums.xml"))
+                parse_file(Path.build_filename(dir, name, null));
+        }
+
+        i = directory.enumerate_children (FileAttribute.STANDARD_NAME, 0, null);
+        while (true)
+        {
+            var info = i.next_file (null);
+            if (info == null)
+                break;
+            var name = info.get_name();
 
-            string path = Path.build_filename(dir, name, null);
-            parse_file(path);
+            if (name.has_suffix(".override"))
+                parse_override(Path.build_filename(dir, name, null));
         }
     }
 }
