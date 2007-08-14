--- kkconsui-0.1/src/texteditor.cc	2003-09-09 23:51:33.000000000 +0200
+++ kkconsui-0.1/src/texteditor.cc	2006-08-28 11:56:10.082753610 +0200
@@ -1940,7 +1940,7 @@
 }
 
 int texteditor::findint(void *p1, void *p2) {
-    return *(int *) p1 != (int) p2;
+    return *(long *) p1 != (long) p2;
 }
 
 int texteditor::findhighline(void *p1, void *p2) {
