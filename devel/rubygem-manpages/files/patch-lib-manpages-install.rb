--- lib/manpages/install.rb.orig	2018-04-11 18:58:24 UTC
+++ lib/manpages/install.rb
@@ -1,4 +1,5 @@
 require "fileutils"
+require "pathname"
 
 module Manpages
   class Install
@@ -26,7 +27,7 @@ module Manpages
 
       begin
         FileUtils.mkdir_p(man_target_file.dirname)
-        FileUtils.ln_s(file, man_target_file, force: true)
+        FileUtils.ln_s(file.relative_path_from(man_target_file.dirname), man_target_file, force: true)
       rescue
         puts "Problems creating symlink #{man_target_file}"
       end
