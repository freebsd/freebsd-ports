--- extconf.rb.orig     Mon Jun 25 00:08:39 2001
+++ extconf.rb  Mon Feb 25 14:02:41 2002
@@ -1,5 +1,17 @@
 require 'mkmf'
 
+glib_config = with_config("glib-config", "glib-config")
+$CFLAGS += " " + %x(#{glib_config} --cflags).chomp
+$LDFLAGS += " " + %x(#{glib_config} --libs).chomp
+
+gtk_config = with_config("gtk-config", "gtk-config")
+$CFLAGS += " " + %x(#{gtk_config} --cflags).chomp
+$LDFLAGS += " " + %x(#{gtk_config} --libs).chomp
+
+libglade_config = with_config("libglade-config", "libglade-config")
+$CFLAGS += " " + %x(#{libglade_config} --cflags).chomp
+$LDFLAGS += " " + %x(#{libglade_config} --libs).chomp
+
 $objs = ["rbglade.o"]
 
 dir_config("glade")
@@ -16,5 +28,3 @@
 end
 
 create_makefile("lglade")
-system('echo LDFLAGS+=`gtk-config --libs` >> Makefile')
-system('echo CFLAGS+=`gtk-config --cflags` >> Makefile')
