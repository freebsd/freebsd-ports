--- extconf.rb.orig	Sat Jun  3 23:56:38 2000
+++ extconf.rb	Wed Feb 28 20:53:13 2001
@@ -1,27 +1,26 @@
 require 'mkmf'
 
-rubygtk_dir = "../gtk"
-rubygtk_dir = ARGV[0] if ARGV[0]
+glib_config = with_config("glib-config", "glib-config")
+imlib_config = with_config("imlib-config", "imlib-config")
+
+while /^--/ =~ ARGV[0]
+  ARGV.shift
+end
+
+rubygtk_dir = ARGV.shift || "../gtk"
 unless FileTest.exist?(rubygtk_dir)
   print "directry '#{rubygtk_dir}' not found.  Please specify Ruby/Gtk source dir.\n"
   exit
 end
-gtklib_dir = []
-`imlib-config --libs-gdk`.split(' ').each do |e|
-  if e=~ /^-L/ then
-    gtklib_dir.push(e)
-  end
-end
 
-$CFLAGS = "-g -I#{rubygtk_dir}/src " + `imlib-config --cflags-gdk`.chomp
-$LDFLAGS = `imlib-config --libs-gdk`.chomp
+$CFLAGS += "-g -I#{rubygtk_dir}/src " + `#{glib_config} --cflags`.chomp + ' ' + `#{imlib_config} --cflags-gdk`.chomp
+$LDFLAGS += `#{glib_config} --libs`.chomp + ' ' +  `#{imlib_config} --libs-gdk`.chomp
 
 have_library("X11", "XOpenDisplay") &&
 have_library("Xi", "XOpenDevice") &&
 have_library("Xext", "XextFindDisplay") &&
 have_library("Xmu", "XmuInternAtom") &&
-have_library("glib", "g_print") &&
-have_library("gdk", "gdk_init") &&
-have_library("gdk_imlib", "gdk_imlib_init") &&
-
+have_func("g_print") &&
+have_func("gdk_init") &&
+have_func("gdk_imlib_init") &&
 create_makefile('gdk_imlib')
