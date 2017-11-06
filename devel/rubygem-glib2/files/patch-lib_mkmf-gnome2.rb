--- lib/mkmf-gnome2.rb.orig	2017-07-08 14:30:53 UTC
+++ lib/mkmf-gnome2.rb
@@ -160,7 +160,7 @@ def add_depend_package(target_name, targ
 
   gem_spec = find_gem_spec(target_name)
   if gem_spec
-    target_source_dir = File.join(gem_spec.full_gem_path, "ext/#{target_name}")
+    target_source_dir = File.join(gem_spec.full_gem_path, "lib")
     target_build_dir = target_source_dir
     add_depend_package_path(target_name,
                             target_source_dir,
