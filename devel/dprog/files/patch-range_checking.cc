--- range_checking.cc.orig	Mon Apr 12 11:10:54 2004
+++ range_checking.cc	Mon Apr 12 11:11:04 2004
@@ -14,9 +14,9 @@
 void
 RangeCheckVisitor::visit (RExpr &rexpr)
 {
-    if (rexpr.begin_br()->is_less() and rexpr.end_br()->is_less())
+    if (rexpr.begin_br()->is_less() && rexpr.end_br()->is_less())
 	return;
-    if (rexpr.begin_br()->is_greater() and rexpr.end_br()->is_greater())
+    if (rexpr.begin_br()->is_greater() && rexpr.end_br()->is_greater())
 	return;
 
     throw new RangeError(rexpr);
