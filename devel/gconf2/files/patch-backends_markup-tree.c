--- backends/markup-tree.c.orig	Fri Jun 11 22:01:00 2004
+++ backends/markup-tree.c	Fri Jun 11 22:01:12 2004
@@ -3070,7 +3070,7 @@
   ParseInfo info;
   char *filename;
   char *text;
-  int length;
+  gsize length;
 
   filename = markup_dir_build_path (root, TRUE, parse_subtree);
   
