--- ./src/ObjectSystem/configSymbol.hh.orig	2014-09-03 02:37:37.000000000 +0200
+++ ./src/ObjectSystem/configSymbol.hh	2014-09-03 02:38:05.000000000 +0200
@@ -50,7 +50,7 @@
 private:
   struct symbolLt
   {
-    bool operator()(const Symbol* d1, const Symbol* d2)
+    bool operator()(const Symbol* d1, const Symbol* d2) const
     {
       return d1->compare(d2) < 0;
     }
