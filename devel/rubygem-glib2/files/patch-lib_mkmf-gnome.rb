--- lib/mkmf-gnome.rb.orig	2019-10-28 15:13:19 UTC
+++ lib/mkmf-gnome.rb
@@ -156,7 +156,7 @@ setup_homebrew
 def add_depend_package(target_name, target_srcdir, top_srcdir, options={})
   gem_spec = find_gem_spec(target_name)
   if gem_spec
-    target_source_dir = File.join(gem_spec.full_gem_path, "ext/#{target_name}")
+    target_source_dir = File.join(gem_spec.full_gem_path, "lib")
     target_build_dir = target_source_dir
     add_depend_package_path(target_name,
                             target_source_dir,
