Index: src/uim-tomoe-gtk.c
diff -u -p src/uim-tomoe-gtk.c.orig src/uim-tomoe-gtk.c
--- src/uim-tomoe-gtk.c.orig	Wed Dec  6 15:48:57 2006
+++ src/uim-tomoe-gtk.c	Mon Apr  9 02:55:56 2007
@@ -24,6 +24,9 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h> 
 #endif /* HAVE_CONFIG_H */
+#ifdef HAVE_LOCALE_H
+#include <locale.h>
+#endif /* HAVE_LOCALE_H */
 #include <gtk/gtk.h>
 #include <uim/uim.h>
 #include <uim/uim-helper.h>
