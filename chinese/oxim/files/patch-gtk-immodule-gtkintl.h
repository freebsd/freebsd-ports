--- src/gtk-immodule/gtkintl.h.orig	Thu Mar 23 08:43:55 2006
+++ src/gtk-immodule/gtkintl.h	Thu Mar 23 08:46:33 2006
@@ -1,7 +1,7 @@
 #ifndef __GTKINTL_H__
 #define __GTKINTL_H__
 #define ENABLE_NLS 1
-#define GTK_LOCALEDIR "/usr/share/locale"
+#define GTK_LOCALEDIR "%%PREFIX%%/share/locale"
 #define GETTEXT_PACKAGE "gtk20"
 
 #ifdef ENABLE_NLS
