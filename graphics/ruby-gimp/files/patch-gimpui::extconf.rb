--- gimpui/extconf.rb.orig	Fri Feb 23 04:55:36 2001
+++ gimpui/extconf.rb	Wed Feb 28 22:42:45 2001
@@ -2,9 +2,8 @@
 require '../mkmf_gimp.rb'
 
 $CFLAGS  += ' ' + GimpConfig::CFLAGS
-$LDFLAGS += ' -lgimp'
+$LDFLAGS += ' ' + GimpConfig::LDFLAGS
 
 if have_gimp_library("gimpui", "gimp_ui_init") and have_header("libgimp/gimpui.h")
-#  $LDFLAGS += ' ' + GimpConfig::LDFLAGS
   create_makefile("gimpui")
 end
