--- parse.c.orig	Sun Apr 20 04:20:19 2003
+++ parse.c	Sun Apr 20 04:21:02 2003
@@ -8519,9 +8519,9 @@
     char *useless = 0;
 
     if (!RTEST(ruby_verbose)) return;
-    if (!node) return;
 
   again:
+    if (!node) return;
     switch (nd_type(node)) {
       case NODE_NEWLINE:
 	node = node->nd_next;
