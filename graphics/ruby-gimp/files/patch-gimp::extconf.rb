--- gimp/extconf.rb.orig	Thu Mar 15 03:50:32 2001
+++ gimp/extconf.rb	Sun Mar 18 04:55:15 2001
@@ -4,9 +4,9 @@
 $CFLAGS  += ' ' + GimpConfig::CFLAGS
 $LDFLAGS += ' ' + GimpConfig::LDFLAGS
 
-if have_library(GimpConfig::LIBGLIB, "g_print") and
-   have_library(GimpConfig::LIBGTK, "gtk_init") and
-   have_library(GimpConfig::LIBGIMP, "gimp_main") and
+if have_func("g_print") and
+   have_func("gtk_init") and
+   have_func("gimp_main") and
    have_header("libgimp/gimp.h")
   have_func("gimp_sysconf_directory")
 
