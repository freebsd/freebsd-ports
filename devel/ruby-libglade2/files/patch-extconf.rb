--- extconf.rb.orig	Wed Jan 24 12:29:18 2001
+++ extconf.rb	Thu Feb  8 04:50:07 2001
@@ -2,6 +2,16 @@
 
 $objs = ["rbglade.o"]
 
+glib_config = with_config("glib-config", "glib-config")
+$CFLAGS += " " + %x(#{glib_config} --cflags).chomp
+$LDFLAGS += " " + %x(#{glib_config} --libs).chomp
+
+gtk_config = with_config("gtk-config", "gtk-config")
+$CFLAGS += " " + %x(#{gtk_config} --cflags).chomp
+$LDFLAGS += " " + %x(#{gtk_config} --libs).chomp
+
+puts $CFLAGS
+
 dir_config("glade")
 dir_config("xml")
 dir_config("z")
@@ -15,4 +25,4 @@
 	end
 end
 
-create_makefile("lglade")
+create_makefile("lglade")
