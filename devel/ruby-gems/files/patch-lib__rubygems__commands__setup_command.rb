--- ./lib/rubygems/commands/setup_command.rb.orig	2009-05-27 18:51:56.000000000 -0400
+++ ./lib/rubygems/commands/setup_command.rb	2009-06-12 00:50:43.889103829 -0400
@@ -115,6 +115,8 @@
 
     install_rdoc
 
+    install_sources
+
     say
     say "-" * 78
     say
@@ -144,6 +146,23 @@
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
     say "Installing gem executable"
 
@@ -152,8 +171,6 @@
     Dir.chdir 'bin' do
       bin_files = Dir['*']
 
-      bin_files.delete 'update_rubygems'
-
       bin_files.each do |bin_file|
         bin_file_formatted = if options[:format_executable] then
                                Gem.default_exec_format % bin_file
