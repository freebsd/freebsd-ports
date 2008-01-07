--- lib/rubygems/installer.rb.orig	2007-12-21 08:43:06.000000000 +0800
+++ lib/rubygems/installer.rb	2007-12-27 09:04:59.000000000 +0800
@@ -134,7 +134,7 @@
     build_extensions
     write_spec
 
-    write_require_paths_file_if_needed
+    # write_require_paths_file_if_needed
 
     # HACK remove?  Isn't this done in multiple places?
     cached_gem = File.join @gem_home, "cache", @gem.split(/\//).pop
