--- src/rbtree.pyx.orig	2007-02-10 06:49:24.000000000 +0800
+++ src/rbtree.pyx	2008-09-09 16:52:56.000000000 +0800
@@ -83,7 +83,7 @@
     cdef int _done
     cdef iter_direction _direction
 
-    def __new__(self, RBTree tree, int itype):
+    def __cinit__(self, RBTree tree, itype):
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
@@ -193,7 +193,7 @@
 cdef class RBTree:
     cdef rbtree_t *_tree
 
-    def __new__(self, mapping=None, cmp=None):
+    def __cinit__(self, mapping=None, cmp=None):
         self._tree = rbtree_alloc()
         rbtree_init(self._tree)
 
@@ -245,7 +245,7 @@
     def __setitem__(self, key, value):
         # calling hash on the key verifies that its not
         # mutilble, as far as a dict would anyway...
-        if isinstance(key, slice):
+        if isinstance(key, key_slice):
             raise ValueError, "setslice is unsupported"
 
         hash(key)
@@ -254,7 +254,7 @@
     def __getitem__(self, key):
         cdef void * v
 
-        if isinstance(key, slice):
+        if isinstance(key, key_slice):
             return self.__doslice__(key)
 
         v = rbtree_get(self._tree, key)
@@ -264,7 +264,7 @@
     def __delitem__(self, key):
         cdef int rc
 
-        if isinstance(key, slice):
+        if isinstance(key, key_slice):
             self.__dodeleteslice__(key)
             return
 
@@ -272,7 +272,7 @@
         if rc != 0: raise KeyError, key
 
 
-    def __doslice__(self, slice):
+    def __doslice__(self, key_slice):
         # This is our hacked up version that getattr will invoke with
         # a slice object. We support key ordering so we could have
         # interger offsets into the results, but really we want to
@@ -280,14 +280,14 @@
         # values between a->z. A new rbtree is returned
         instance = self.__class__()
         rbtree_do_slice(self._tree,
-                        slice.start,
-                        slice.stop,
-                        slice.step,
+                        key_slice.start,
+                        key_slice.stop,
+                        key_slice.step,
                         (<RBTree>instance)._tree)
         return instance
 
-    def __dodeleteslice__(self, slice):
-        rbtree_do_del_slice(self._tree, slice.start, slice.stop, slice.step)
+    def __dodeleteslice__(self, key_slice):
+        rbtree_do_del_slice(self._tree, key_slice.start, key_slice.stop, key_slice.step)
 
     def get(self, key, default=None):
         try:
