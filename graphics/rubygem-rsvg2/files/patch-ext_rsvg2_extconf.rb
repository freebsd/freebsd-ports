--- ext/rsvg2/extconf.rb.orig	2016-01-19 22:20:58 UTC
+++ ext/rsvg2/extconf.rb
@@ -30,7 +30,7 @@ rescue LoadError
   require 'mkmf-gnome2'
 end
 
-["glib2", "gdk_pixbuf2"].each do |package|
+["cairo", "glib2", "gdk_pixbuf2"].each do |package|
   directory = "#{package}#{version_suffix}"
   build_dir = "#{directory}/tmp/#{RUBY_PLATFORM}/#{package}/#{RUBY_VERSION}"
   add_depend_package(package, "#{directory}/ext/#{package}",
