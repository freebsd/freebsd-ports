--- setup.rb.orig	2007-12-21 09:15:55.000000000 +0800
+++ setup.rb	2007-12-25 22:39:23.000000000 +0800
@@ -222,6 +222,22 @@
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
+
 # Remove stubs
 
 def stub?(path)
@@ -268,3 +284,4 @@
   puts "No library stubs found."
 end
 
+install_sources
