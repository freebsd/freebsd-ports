--- ./src/rbtree.pyx.orig	Sat Feb 10 06:49:24 2007
+++ ./src/rbtree.pyx	Mon Mar 26 10:19:44 2007
@@ -83,7 +83,7 @@
     cdef int _done
     cdef iter_direction _direction
 
-    def __new__(self, RBTree tree, int itype):
+    def __new__(self, RBTree tree, itype):
         self._T = tree
         self._iter = NULL
         self._type = itype
@@ -93,7 +93,7 @@
     property direction:
         def __get__(self):
             return self._direction
-        def __set__(self, int value):
+        def __set__(self, value):
             self._direction = value
 
     cdef _position(self, iter_direction direction):
