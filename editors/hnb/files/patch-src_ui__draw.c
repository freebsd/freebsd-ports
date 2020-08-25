Make sure the globals in the file are static to prevent duplicate symbol during
linking.
--- src/ui_draw.c.orig	2020-08-25 00:53:47 UTC
+++ src/ui_draw.c
@@ -39,9 +39,9 @@
 
 #define KEEPLINES 5
 
-int nodes_above;
-int active_line;
-int nodes_below;
+static int nodes_above;
+static int active_line;
+static int nodes_below;
 
 static Node *up (Node *sel, Node *node)
 {
