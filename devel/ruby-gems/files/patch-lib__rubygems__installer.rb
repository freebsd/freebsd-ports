--- ./lib/rubygems/installer.rb.orig	2009-05-07 20:49:03.000000000 -0400
+++ ./lib/rubygems/installer.rb	2009-06-12 00:49:09.432934400 -0400
@@ -219,8 +219,6 @@
     build_extensions
     write_spec
 
-    write_require_paths_file_if_needed
-
     # HACK remove?  Isn't this done in multiple places?
     cached_gem = File.join @gem_home, "cache", @gem.split(/\//).pop
     unless File.exist? cached_gem then
