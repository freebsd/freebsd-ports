--- lib/mkmf-gnome.rb.orig	2023-01-23 17:54:17 UTC
+++ lib/mkmf-gnome.rb
@@ -186,7 +186,7 @@ def add_depend_package(target_name, target_srcdir, top
 
   gem_spec = find_gem_spec(target_name)
   raise "depended gem isn't found: #{target_name}" unless gem_spec
-  target_source_dir = File.join(gem_spec.full_gem_path, "ext/#{target_name}")
+  target_source_dir = File.join(gem_spec.full_gem_path, "lib")
   target_build_dir = target_source_dir
   add_depend_package_path(target_name, target_source_dir, target_build_dir)
 end
@@ -447,7 +447,7 @@ def check_cairo(options={})
     cairo_gem_spec = find_gem_spec("cairo")
     if cairo_gem_spec
       rcairo_source_dir = cairo_gem_spec.full_gem_path
-      rcairo_ext_source_dir = File.join(rcairo_source_dir, "ext", "cairo")
+      rcairo_ext_source_dir = File.join(rcairo_source_dir, "lib")
       add_depend_package_path("cairo",
                               rcairo_ext_source_dir,
                               rcairo_ext_source_dir)
