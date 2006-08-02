
$FreeBSD$

--- amarok/src/expression.h.orig
+++ amarok/src/expression.h
@@ -27,8 +27,8 @@
 {
     QString field;
     QString text;
-    bool negate: 1;
-    enum { Contains, Less, More } match: 2;
+    bool negate;
+    enum { Contains, Less, More } match;
     expression_element(): negate( false ), match( Contains ) { }
 };
 typedef QValueVector<expression_element> or_list;
