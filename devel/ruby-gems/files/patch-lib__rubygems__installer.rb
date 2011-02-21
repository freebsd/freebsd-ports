--- lib/rubygems/installer.rb.orig	2011-02-10 14:03:04.000000000 +0000
+++ lib/rubygems/installer.rb	2011-02-10 14:05:02.000000000 +0000
@@ -171,7 +171,7 @@
     generate_bin
     write_spec
 
-    write_require_paths_file_if_needed if Gem::QUICKLOADER_SUCKAGE
+    # write_require_paths_file_if_needed if Gem::QUICKLOADER_SUCKAGE
 
     # HACK remove?  Isn't this done in multiple places?
     cached_gem = File.join @gem_home, "cache", @gem.split(/\//).pop
