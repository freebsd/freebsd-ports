--- extconf.rb.orig	Mon Jun 25 07:08:39 2001
+++ extconf.rb	Tue Jun 26 06:06:49 2001
@@ -1,5 +1,13 @@
 require 'mkmf'
 
+glib_config = with_config("glib-config", "glib-config")
+$CFLAGS += " " + %x(#{glib_config} --cflags).chomp
+$LDFLAGS += " " + %x(#{glib_config} --libs).chomp
+
+gtk_config = with_config("gtk-config", "gtk-config")
+$CFLAGS += " " + %x(#{gtk_config} --cflags).chomp
+$LDFLAGS += " " + %x(#{gtk_config} --libs).chomp
+
 $objs = ["rbglade.o"]
 
 dir_config("glade")
@@ -16,5 +24,3 @@
 end
 
 create_makefile("lglade")
-system('echo LDFLAGS+=`gtk-config --libs` >> Makefile')
-system('echo CFLAGS+=`gtk-config --cflags` >> Makefile')
