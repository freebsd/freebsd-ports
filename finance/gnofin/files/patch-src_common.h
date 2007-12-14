--- src/common.h.orig	2007-12-13 19:50:36.000000000 +0100
+++ src/common.h	2007-12-13 19:50:59.000000000 +0100
@@ -24,6 +24,8 @@
 # include <config.h>
 #endif
 
+#include <string.h>
+
 #include <glib.h>
 #include <libgnome/gnome-defs.h>
 #include <libgnome/gnome-i18n.h>  /* defines _() and N_() macros */
