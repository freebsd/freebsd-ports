--- src/layout_util.c.orig	2019-07-26 18:19:11 UTC
+++ src/layout_util.c
@@ -62,6 +62,8 @@
 #include <gdk/gdkkeysyms.h> /* for keyboard values */
 #include "keymap_template.c"
 
+#include <sys/wait.h> /* for WEXITSTATUS */
+
 #define MENU_EDIT_ACTION_OFFSET 16
 #define FILE_COLUMN_POINTER 0
 
