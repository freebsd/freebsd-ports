--- software/tlprender/src/Shape.h.orig	Thu Dec 26 20:32:07 2002
+++ software/tlprender/src/Shape.h	Fri Oct 29 14:14:20 2004
@@ -63,10 +63,10 @@
 } //namespace tlprender
 
 namespace std {
-    struct less<tlprender::Shape *> {
+    template <> struct less<tlprender::Shape *> {
     bool operator()(tlprender::Shape *&p1, tlprender::Shape *&p2);
   };
-  struct less<tlprender::Shape> {
+  template <> struct less<tlprender::Shape> {
     bool operator()(const tlprender::Shape &p1, const tlprender::Shape &p2);
   };
 }
