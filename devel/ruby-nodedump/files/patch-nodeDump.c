[ruby-core: 00560]

--- nodeDump.c.orig	Fri Jul 26 20:14:32 2002
+++ nodeDump.c	Thu Oct 24 03:32:21 2002
@@ -103,5 +103,4 @@ static void doDump(NODE *n, int level) {
   lp(level, "%s: ", node_names[type]);
 
- again:
   switch (type) {
 
@@ -117,10 +116,9 @@ static void doDump(NODE *n, int level) {
   case NODE_OR:
     nl();
-    doDump(n->nd_1st, level + 1);
-    if (n->nd_2nd && nd_type(n->nd_2nd)) {
-      n = n->nd_2nd;
-      goto again;
-    }
-    doDump(n->nd_2nd, level + 1);
+    ++level;
+    do {
+      doDump(n->nd_1st, level);
+    } while (n->nd_2nd && (type == nd_type(n = n->nd_2nd)));
+    doDump(n, level);
     break;
     
@@ -352,4 +350,7 @@ static void doDump(NODE *n, int level) {
   case NODE_DREGX:
   case NODE_DREGX_ONCE:
+#ifdef NODE_DSYM
+  case NODE_DSYM:
+#endif
     dumpLiteral(n->nd_lit, level+1);
     n1 = n->nd_next;
@@ -677,8 +678,14 @@ static void doDump(NODE *n, int level) {
   case NODE_WHILE:
     nl();
-    lp(level+1, "Condition:\n");
-    doDump(n->nd_cond, level+2);
+    if (n->nd_state) {
+      lp(level+1, "Condition:\n");
+      doDump(n->nd_cond, level+2);
+    }
     lp(level+1, "Body:\n");
     doDump(n->nd_body, level+2);
+    if (!n->nd_state) {
+      lp(level+1, "Condition:\n");
+      doDump(n->nd_cond, level+2);
+    }
     break;
     
