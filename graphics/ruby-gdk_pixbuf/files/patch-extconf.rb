--- extconf.rb.orig	Fri Mar 31 06:21:47 2000
+++ extconf.rb	Wed Feb 28 21:18:34 2001
@@ -1,26 +1,25 @@
 require 'mkmf'
 
-rubygtk_dir = "../gtk"
-rubygtk_dir = ARGV[0] if ARGV[0]
+glib_config = with_config("glib-config", "glib-config")
+gdk_pixbuf_config = with_config("gdk-pixbuf-config", "gdk-pixbuf-config")
+
+while /^--/ =~ ARGV[0]
+  ARGV.shift
+end
+
+rubygtk_dir = ARGV.shift || "../gtk"
 unless FileTest.exist?(rubygtk_dir)
   raise "directry #{rubygtk_dir} not found.  Please specify Ruby/Gtk source dir."
 end
-gtklib_dir = []
-`gtk-config --libs`.split(' ').each do |e|
-  if e=~ /^-L/ then
-    gtklib_dir.push(e)
-  end
-end
 
-$CFLAGS = "-I#{rubygtk_dir}/src " + `gdk-pixbuf-config --cflags`.chomp
-$LDFLAGS = `gdk-pixbuf-config --libs`.chomp
+$CFLAGS += "-I#{rubygtk_dir}/src " + `#{glib_config} --cflags`.chomp + ' ' + `#{gdk_pixbuf_config} --cflags`.chomp
+$LDFLAGS += `#{glib_config} --libs`.chomp + ' ' + `#{gdk_pixbuf_config} --libs`.chomp
 
 have_library("X11", "XOpenDisplay") &&
 have_library("Xi", "XOpenDevice") &&
 have_library("Xext", "XextFindDisplay") &&
 have_library("Xmu", "XmuInternAtom") &&
-have_library("glib", "g_print") &&
-have_library("gdk", "gdk_init") &&
-have_library("gdk_pixbuf", "gdk_pixbuf_new") &&
-
+have_func("g_print") &&
+have_func("gdk_init") &&
+have_func("gdk_pixbuf_new") &&
 create_makefile('gdk_pixbuf')
