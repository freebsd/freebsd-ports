--- src/gtk-immodule/gtkintl.h.orig	2009-01-07 11:32:19.000000000 +0800
+++ src/gtk-immodule/gtkintl.h	2009-12-27 14:43:18.000000000 +0800
@@ -1,6 +1,6 @@
 #ifndef __GTKINTL_H__
 #define __GTKINTL_H__
-#define GTK_LOCALEDIR "/usr/share/locale"
+#define GTK_LOCALEDIR "%%PREFIX%%/share/locale"
 #define GETTEXT_PACKAGE "gtk20"
 
 #include <langinfo.h>
