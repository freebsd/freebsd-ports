--- gimpui/extconf.rb.orig	Thu Mar 15 10:48:42 2001
+++ gimpui/extconf.rb	Sun Mar 18 04:55:36 2001
@@ -4,11 +4,11 @@
 $CFLAGS  += ' ' + GimpConfig::CFLAGS
 $LDFLAGS += ' ' + GimpConfig::LDFLAGS
 
-if have_library(GimpConfig::LIBGLIB, "g_print") and
-   have_library(GimpConfig::LIBGDK, "gdk_init") and
-   have_library(GimpConfig::LIBGTK, "gtk_init") and
-   have_library(GimpConfig::LIBGIMP, "gimp_main") and
-   have_library(GimpConfig::LIBGIMPUI, "gimp_ui_init") and
+if have_func("g_print") and
+   have_func("gdk_init") and
+   have_func("gtk_init") and
+   have_func("gimp_main") and
+   have_func("gimp_ui_init") and
    have_header("libgimp/gimpui.h")
 
   have_func("gimp_mem_size_entry_new")
