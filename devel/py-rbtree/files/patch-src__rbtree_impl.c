--- ./src/rbtree_impl.c.orig	Mon May  8 11:00:16 2006
+++ ./src/rbtree_impl.c	Mon May  8 11:01:48 2006
@@ -43,10 +43,11 @@
 int
 rbtree_node_compare(PyObject *x, PyObject *y)
 {
+  int gt, lt;
   /* a three way compare that should work with whatever objects support */
-  int gt = PyObject_RichCompareBool(x,y, Py_GT);
+  gt = PyObject_RichCompareBool(x,y, Py_GT);
   if (gt == 1) return 1;
-  int lt = PyObject_RichCompareBool(x,y, Py_LT);
+  lt = PyObject_RichCompareBool(x,y, Py_LT);
   if (lt == 1)  return -1;
   return 0;
 }
@@ -626,16 +627,18 @@
 
 rbtree_node_t *
 tree_min(rbtree_t *T, rbtree_node_t *x) {
+  rbtree_node_t *n;
   if (x == NULL) x = T->root;
-  rbtree_node_t *n = __tree_min(T, x);
+  n = __tree_min(T, x);
   if (n == T->nil) n = NULL;
   return n;
 }
 
 rbtree_node_t *
 tree_max(rbtree_t *T, rbtree_node_t *x) {
+  rbtree_node_t *n;
   if (x == NULL) x = T->root;
-  rbtree_node_t *n = __tree_max(T, x);
+  n = __tree_max(T, x);
   if (n == T->nil) n = NULL;
   return n;
 }
