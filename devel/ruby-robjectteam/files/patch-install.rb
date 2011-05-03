--- install.rb.orig	2003-07-08 21:24:10.000000000 +0100
+++ install.rb	2011-04-18 11:17:43.000000000 +0100
@@ -36,7 +36,7 @@
 =end
 
 require 'getoptlong'
-require 'ftools'
+require 'fileutils'
 require 'find'
 
 SOURCE_DIR = 'objectteam'
@@ -81,7 +81,7 @@
 
 def install(source, destination)
   begin
-    File.install(source, destination, 0644, true) 
+    FileUtils.install(source, destination, :mode => 0644, :verbose => true) 
   rescue Errno::EACCES
     puts "Access not permitted! #{$!}"
   rescue
@@ -104,7 +104,7 @@
     #install directory
     instdir = (instdir or install_dir())
     #make sink directory
-    File.makedirs(File.join(instdir, LIBDIR))
+    FileUtils.mkdir_p(File.join(instdir, LIBDIR))
     #all ruby files beneath SOURCE_DIR
     Find.find(SOURCE_DIR) { |f|
       install(f, File.join(instdir, f)) if f =~ /.rb$/

