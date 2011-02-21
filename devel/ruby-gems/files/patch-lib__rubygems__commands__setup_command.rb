--- lib/rubygems/commands/setup_command.rb.orig	2011-02-10 14:01:36.000000000 +0000
+++ lib/rubygems/commands/setup_command.rb	2011-02-10 14:01:45.000000000 +0000
@@ -112,6 +112,8 @@
 
     install_rdoc
 
+    install_sources
+
     say
     if @verbose then
       say "-" * 78
@@ -147,6 +149,23 @@
     end
   end
 
+  def install_sources
+    say "Installing sources"
+
+    $: << "lib"
+   require 'rubygems'
+   require 'rubygems/builder'
+   require 'rubygems/installer'
+   require 'rubygems/config_file'
+
+    Dir.chdir("pkgs/sources") do
+        load "sources.gemspec"
+        spec = Gem.sources_spec
+        gem_file = Gem::Builder.new(spec).build
+        Gem::Installer.new(gem_file).install
+    end
+  end
+
   def install_executables(bin_dir)
     say "Installing gem executable" if @verbose
 
@@ -155,8 +174,6 @@
     Dir.chdir 'bin' do
       bin_files = Dir['*']
 
-      bin_files.delete 'update_rubygems'
-
       bin_files.each do |bin_file|
         bin_file_formatted = if options[:format_executable] then
                                Gem.default_exec_format % bin_file
