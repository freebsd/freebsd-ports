--- parse.c.orig	Sun Apr 20 04:22:00 2003
+++ parse.c	Sun Apr 20 04:23:40 2003
@@ -9514,9 +9514,9 @@
     char *useless = 0;
 
     if (!RTEST(ruby_verbose)) return;
-    if (!node) return;
 
   again:
+    if (!node) return;
     switch (nd_type(node)) {
       case NODE_NEWLINE:
 	node = node->nd_next;
