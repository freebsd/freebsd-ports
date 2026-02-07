Make sure the globals in the file are static to prevent duplicate symbol during
linking.
--- src/ui.c.orig	2020-08-25 00:53:34 UTC
+++ src/ui.c
@@ -32,9 +32,9 @@
 #define UI_C
 #include "ui.h"
 
-int nodes_above;
-int active_line;
-int nodes_below;
+static int nodes_above;
+static int active_line;
+static int nodes_below;
 int ui_inited = 0;
 
 void ui_init ()
