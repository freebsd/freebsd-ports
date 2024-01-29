--- electron/shell/browser/ui/gtk/menu_gtk.h.orig	2023-12-20 13:32:58 UTC
+++ electron/shell/browser/ui/gtk/menu_gtk.h
@@ -5,6 +5,8 @@
 #ifndef ELECTRON_SHELL_BROWSER_UI_GTK_MENU_GTK_H_
 #define ELECTRON_SHELL_BROWSER_UI_GTK_MENU_GTK_H_
 
+#include <vector>
+
 #include "base/functional/callback.h"
 #include "base/memory/raw_ptr.h"
 #include "ui/base/glib/scoped_gobject.h"
