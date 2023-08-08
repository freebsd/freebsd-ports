--- ext/arrow/extconf.rb.orig	2022-09-13 15:47:51 UTC
+++ ext/arrow/extconf.rb
@@ -65,7 +65,7 @@ unless required_pkg_config_package([
 end
 
 [
-  ["glib2", "ext/glib2"],
+  ["glib2", "lib"],
 ].each do |name, relative_source_dir|
   spec = find_gem_spec(name)
   source_dir = File.join(spec.full_gem_path, relative_source_dir)
