--- ext/cairo-gobject/extconf.rb.orig	2016-01-19 21:24:25 UTC
+++ ext/cairo-gobject/extconf.rb
@@ -45,7 +45,7 @@ rescue LoadError
   require "mkmf-gnome2"
 end
 
-["glib2"].each do |package|
+["glib2", "cairo"].each do |package|
   directory = "#{package}#{version_suffix}"
   build_dir = "#{directory}/tmp/#{RUBY_PLATFORM}/#{package}/#{RUBY_VERSION}"
   add_depend_package(package, "#{directory}/ext/#{package}",
