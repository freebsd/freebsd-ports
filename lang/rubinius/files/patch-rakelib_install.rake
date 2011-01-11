--- rakelib/install.rake.orig	2011-01-10 17:37:36.000000000 -0800
+++ rakelib/install.rake	2011-01-10 17:38:07.000000000 -0800
@@ -137,16 +137,6 @@
       exe = "#{BUILD_CONFIG[:bindir]}/#{BUILD_CONFIG[:program_name]}"
       install "vm/vm", install_dir(exe), :mode => 0755, :verbose => true
 
-      # Create symlinks for common commands
-      begin
-        ["ruby", "rake", "gem", "irb", "rdoc", "ri"].each do |command|
-          name = "#{BUILD_CONFIG[:bindir]}/#{command}"
-          File.symlink BUILD_CONFIG[:program_name], install_dir(name)
-        end
-      rescue NotImplementedError
-        # ignore
-      end
-
       STDOUT.puts <<-EOM
 --------
 
