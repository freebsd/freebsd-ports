--- src/Kernel/Types/tree.cpp.orig	2015-12-16 08:40:02 UTC
+++ src/Kernel/Types/tree.cpp
@@ -197,7 +197,7 @@ operator << (tm_ostream& out, tree t) {
 }
 
 void
-print_tree (tree t, int tab) {
+print_tree (tree t, int tab=0) {
   int i;
   for (i=0; i<tab; i++) cout << " ";
   if (is_atomic (t)) cout << t->label << "\n";
