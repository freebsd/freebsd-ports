--- extconf.rb.orig	Sun Mar 24 10:14:53 2002
+++ extconf.rb	Sun Apr  7 02:59:24 2002
@@ -1,3 +1,9 @@
 require 'mkmf'
-have_library("Imlib2", "imlib_create_image")
-create_makefile("imlib2")
+
+imlib2_config = with_config("imlib2-config", "imlib2-config")
+
+$CFLAGS << ' ' << `#{imlib2_config} --cflags`.chomp
+$LDFLAGS << ' ' << `#{imlib2_config} --libs`.chomp
+
+have_library("Imlib2", "imlib_create_image") and
+  create_makefile("imlib2")
