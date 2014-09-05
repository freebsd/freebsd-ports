--- ./src/Kernel/Types/tree.hpp.orig	2014-08-28 13:09:50.435479991 -0400
+++ ./src/Kernel/Types/tree.hpp	2014-08-28 13:10:38.328730991 -0400
@@ -84,7 +84,7 @@
   friend tree& operator << (tree& t, array<tree> a);
   friend tm_ostream& operator << (tm_ostream& out, tree t);
   friend tree operator * (tree t1, tree t2);
-  friend void print_tree (tree t, int tab=0);
+  friend void print_tree (tree t, int tab);
   friend list<tree> as_trees (list<pointer> l);
   friend class tree_pointer_rep;
   friend class tree_position_rep;
