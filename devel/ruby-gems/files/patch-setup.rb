--- setup.rb~	2008-06-22 08:51:11.000000000 +0900
+++ setup.rb	2008-07-03 17:39:54.000000000 +0900
@@ -158,7 +158,7 @@
 Dir.chdir 'bin' do
   bin_files = Dir['*']
 
-  bin_files.delete 'update_rubygems'
+#  bin_files.delete 'update_rubygems'
 
   bin_files.each do |bin_file|
     bin_file_formatted = if format_executable then
@@ -299,6 +299,23 @@
   puts "Set the GEM_HOME environment variable if you want RDoc generated"
 end
 
+# Install sources
+
+def install_sources
+  $: << "lib"
+  require 'rubygems'
+  require 'rubygems/builder'
+  require 'rubygems/installer'
+  require 'rubygems/config_file'
+  Dir.chdir("pkgs/sources") do
+    load "sources.gemspec"
+    spec = Gem.sources_spec
+    gem_file = Gem::Builder.new(spec).build
+    Gem::Installer.new(gem_file).install
+  end
+end
+install_sources
+
 puts
 puts "-" * 78
 puts
