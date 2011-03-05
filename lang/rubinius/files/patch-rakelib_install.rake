--- rakelib/install.rake.orig	2011-03-03 17:39:38.000000000 -0800
+++ rakelib/install.rake	2011-03-03 17:39:44.000000000 -0800
@@ -138,17 +138,6 @@
       exe = "#{BUILD_CONFIG[:bindir]}/#{BUILD_CONFIG[:program_name]}"
       install "vm/vm", install_dir(exe), :mode => 0755, :verbose => true
 
-      # Create symlinks for common commands
-      begin
-        ["ruby", "rake", "gem", "irb", "rdoc", "ri"].each do |command|
-          name = install_dir("#{BUILD_CONFIG[:bindir]}/#{command}")
-          File.delete name if File.exists? name
-          File.symlink BUILD_CONFIG[:program_name], name
-        end
-      rescue NotImplementedError
-        # ignore
-      end
-
       STDOUT.puts <<-EOM
 --------
 
