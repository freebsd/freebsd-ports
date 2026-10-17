Description: Fix Python 2 leftovers: the SmallLRUCache key/value/item
  iterators only define next(); LinkedListLRUCache uses dict.has_key() and
  dict.iterkeys(); SmallLRUCache.update() keeps a dict keys view as its LRU
  list and evicts with a lazy map() that never runs.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/cache.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/cache.py
@@ -406,7 +406,7 @@ class SmallLRUCache(dict):
             self.i = 0
         def __iter__(self):
             return self
-        def next(self):
+        def __next__(self):
             precondition(self.i <= len(self.c._lru), "The iterated SmallLRUCache doesn't have this many elements.  Most likely this is because someone altered the contents of the LRUCache while the iteration was in progress.", self.i, self.c)
             if self.i == len(self.c._lru):
                 raise StopIteration()
@@ -414,6 +414,7 @@ class SmallLRUCache(dict):
             k = self.c._lru[self.i]
             self.i += 1
             return (k, dict.__getitem__(self.c, k),)
+        next = __next__
 
     class KeyIterator:
         def __init__(self, c):
@@ -421,7 +422,7 @@ class SmallLRUCache(dict):
             self.i = 0
         def __iter__(self):
             return self
-        def next(self):
+        def __next__(self):
             precondition(self.i <= len(self.c._lru), "The iterated SmallLRUCache doesn't have this many elements.  Most likely this is because someone altered the contents of the LRUCache while the iteration was in progress.", self.i, self.c)
             if self.i == len(self.c._lru):
                 raise StopIteration()
@@ -429,6 +430,7 @@ class SmallLRUCache(dict):
             k = self.c._lru[self.i]
             self.i += 1
             return k
+        next = __next__
 
     class ValueIterator:
         def __init__(self, c):
@@ -436,7 +438,7 @@ class SmallLRUCache(dict):
             self.i = 0
         def __iter__(self):
             return self
-        def next(self):
+        def __next__(self):
             precondition(self.i <= len(self.c._lru), "The iterated SmallLRUCache doesn't have this many elements.  Most likely this is because someone altered the contents of the LRUCache while the iteration was in progress.", self.i, self.c)
             if self.i == len(self.c._lru):
                 raise StopIteration()
@@ -444,6 +446,7 @@ class SmallLRUCache(dict):
             k = self.c._lru[self.i]
             self.i += 1
             return dict.__getitem__(self.c, k)
+        next = __next__
 
     def __init__(self, initialdata={}, maxsize=128):
         dict.__init__(self, initialdata)
@@ -547,7 +550,7 @@ class SmallLRUCache(dict):
                     if len(self) == self._maxsize:
                         break
                     dict.__setitem__(self, k, v)
-            self._lru = dict.keys(self)
+            self._lru = list(dict.keys(self))
             assert self._assert_invariants()
             return self
 
@@ -559,7 +562,8 @@ class SmallLRUCache(dict):
 
         over = len(self) - self._maxsize
         if over > 0:
-            map(dict.__delitem__, [self]*over, self._lru[:over])
+            for k in self._lru[:over]:
+                dict.__delitem__(self, k)
             del self._lru[:over]
 
         assert self._assert_invariants()
@@ -658,8 +662,8 @@ class LinkedListLRUCache:
                     return True
             return False
         for k in lliterkeys(self):
-            _assert(self.d.has_key(k), "Each key in the linked list is required to be in the dict.", k)
-        for k in self.d.iterkeys():
+            _assert(k in self.d, "Each key in the linked list is required to be in the dict.", k)
+        for k in self.d:
             _assert(llhaskey(self, k), "Each key in the dict is required to be in the linked list.", k)
         _assert(lllen(self) == len(self.d), "internal consistency", self, self.d)
         _assert(len(self.d) <= self._maxsize, "Size is required to be <= maxsize.")
@@ -703,7 +707,7 @@ class LinkedListLRUCache:
     def insert(self, key, item=None):
         return self.__setitem__(key, item)
     def __delitem__(self, obj, default=None, strictkey=True):
-        if self.d.has_key(obj):
+        if obj in self.d:
             nobj = self.d[obj]
             if nobj.prev:
                 nobj.prev.next = nobj.next
