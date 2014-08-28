--- ./src/Kernel/Types/tree.cpp.orig	2014-08-28 13:09:45.011154991 -0400
+++ ./src/Kernel/Types/tree.cpp	2014-08-28 13:10:18.050663990 -0400
@@ -195,7 +195,7 @@
 }
 
 void
-print_tree (tree t, int tab) {
+print_tree (tree t, int tab=0) {
   int i;
   for (i=0; i<tab; i++) cout << " ";
   if (is_atomic (t)) cout << t->label << "\n";
