--- src/layout_util.c.orig	2017-12-31 12:31:21 UTC
+++ src/layout_util.c
@@ -59,6 +59,7 @@
 #include "desktop_file.h"
 
 #include <gdk/gdkkeysyms.h> /* for keyboard values */
+#include <sys/wait.h> /* for WEXITSTATUS */
 #include "keymap_template.c"
 
 #define MENU_EDIT_ACTION_OFFSET 16
