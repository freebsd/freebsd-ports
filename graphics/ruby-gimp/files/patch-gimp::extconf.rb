--- gimp/extconf.rb.orig	Fri Feb 23 04:53:23 2001
+++ gimp/extconf.rb	Wed Feb 28 22:43:04 2001
@@ -2,8 +2,8 @@
 require '../mkmf_gimp.rb'
 
 $CFLAGS  += ' ' + GimpConfig::CFLAGS
+$LDFLAGS += ' ' + GimpConfig::LDFLAGS
 
 if have_gimp_library("gimp", "gimp_main") and have_header("libgimp/gimp.h")
-#  $LDFLAGS += ' ' + GimpConfig::LDFLAGS
   create_makefile("gimp")
 end
