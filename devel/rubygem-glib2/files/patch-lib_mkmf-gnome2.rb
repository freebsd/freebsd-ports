--- lib/mkmf-gnome2.rb.orig	2016-01-19 21:17:20 UTC
+++ lib/mkmf-gnome2.rb
@@ -152,7 +152,7 @@ end
 def add_depend_package(target_name, target_srcdir, top_srcdir, options={})
   gem_spec = find_gem_spec(target_name)
   if gem_spec
-    target_source_dir = File.join(gem_spec.full_gem_path, "ext/#{target_name}")
+    target_source_dir = File.join(gem_spec.full_gem_path, "lib")
     target_build_dir = target_source_dir
     add_depend_package_path(target_name,
                             target_source_dir,
