Description: Fix SmallOrderedDict on Python 3: dict keys views as the LRU
  list, a lazy map() for eviction, len() of filter() objects in
  _assert_invariants() (TypeError on construction with asserts on),
  iteritems()/iterkeys() on the dict passed to update(), iterators that only
  define next(), check the key before the end and return the position
  instead of the key, and an inverted test in setdefault(). The OrderedDict
  iterators only defined next() too.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/odict.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/odict.py
@@ -386,14 +386,15 @@ class SmallOrderedDict(dict):
             self.i = 0
         def __iter__(self):
             return self
-        def next(self):
+        def __next__(self):
             precondition(self.i <= len(self.c._lru), "The iterated SmallOrderedDict doesn't have this many elements.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c)
-            precondition(dict.__contains__(self.c, self.c._lru[self.i]), "The iterated SmallOrderedDict doesn't have this key.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c._lru[self.i], self.c)
             if self.i == len(self.c._lru):
                 raise StopIteration()
-            k = self.i
+            precondition(dict.__contains__(self.c, self.c._lru[self.i]), "The iterated SmallOrderedDict doesn't have this key.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c._lru[self.i], self.c)
+            k = self.c._lru[self.i]
             self.i += 1
             return (k, dict.__getitem__(self.c, k),)
+        next = __next__
 
     class KeyIterator:
         def __init__(self, c):
@@ -401,14 +402,15 @@ class SmallOrderedDict(dict):
             self.i = 0
         def __iter__(self):
             return self
-        def next(self):
+        def __next__(self):
             precondition(self.i <= len(self.c._lru), "The iterated SmallOrderedDict doesn't have this many elements.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c)
-            precondition(dict.__contains__(self.c, self.c._lru[self.i]), "The iterated SmallOrderedDict doesn't have this key.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c._lru[self.i], self.c)
             if self.i == len(self.c._lru):
                 raise StopIteration()
-            k = self.i
+            precondition(dict.__contains__(self.c, self.c._lru[self.i]), "The iterated SmallOrderedDict doesn't have this key.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c._lru[self.i], self.c)
+            k = self.c._lru[self.i]
             self.i += 1
             return k
+        next = __next__
 
     class ValueIterator:
         def __init__(self, c):
@@ -416,30 +418,32 @@ class SmallOrderedDict(dict):
             self.i = 0
         def __iter__(self):
             return self
-        def next(self):
+        def __next__(self):
             precondition(self.i <= len(self.c._lru), "The iterated SmallOrderedDict doesn't have this many elements.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c)
-            precondition(dict.__contains__(self.c, self.c._lru[self.i]), "The iterated SmallOrderedDict doesn't have this key.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c._lru[self.i], self.c)
             if self.i == len(self.c._lru):
                 raise StopIteration()
-            k = self.i
+            precondition(dict.__contains__(self.c, self.c._lru[self.i]), "The iterated SmallOrderedDict doesn't have this key.  Most likely this is because someone altered the contents of the OrderedDict while the iteration was in progress.", self.i, self.c._lru[self.i], self.c)
+            k = self.c._lru[self.i]
             self.i += 1
             return dict.__getitem__(self.c, k)
+        next = __next__
 
     def __init__(self, initialdata={}, maxsize=128):
         dict.__init__(self, initialdata)
-        self._lru = initialdata.keys() # contains keys
+        self._lru = list(initialdata.keys()) # contains keys
         self._maxsize = maxsize
         over = len(self) - self._maxsize
         if over > 0:
-            map(dict.__delitem__, [self]*over, self._lru[:over])
+            for k in self._lru[:over]:
+                dict.__delitem__(self, k)
             del self._lru[:over]
         assert self._assert_invariants()
 
     def _assert_invariants(self):
         _assert(len(self._lru) <= self._maxsize, "Size is required to be <= maxsize.")
-        _assert(len(filter(lambda x: dict.__contains__(self, x), self._lru)) == len(self._lru), "Each key in self._lru is required to be in dict.", filter(lambda x: dict.__contains__(self, x), self._lru), len(self._lru), self._lru, len(self), self)
-        _assert(len(filter(lambda x: x in self._lru, self.keys())) == len(self), "Each key in dict is required to be in self._lru.", filter(lambda x: x not in self._lru, self.keys()), len(self._lru), self._lru, len(self), self)
-        _assert(len(self._lru) == len(self), "internal consistency", filter(lambda x: x not in self.keys(), self._lru), len(self._lru), self._lru, len(self), self)
+        _assert(len([x for x in self._lru if dict.__contains__(self, x)]) == len(self._lru), "Each key in self._lru is required to be in dict.", [x for x in self._lru if not dict.__contains__(self, x)], len(self._lru), self._lru, len(self), self)
+        _assert(len([x for x in self.keys() if x in self._lru]) == len(self), "Each key in dict is required to be in self._lru.", [x for x in self.keys() if x not in self._lru], len(self._lru), self._lru, len(self), self)
+        _assert(len(self._lru) == len(self), "internal consistency", [x for x in self._lru if x not in self.keys()], len(self._lru), self._lru, len(self), self)
         _assert(len(self._lru) <= self._maxsize, "internal consistency", len(self._lru), self._lru, self._maxsize)
         return True
 
@@ -451,7 +455,7 @@ class SmallOrderedDict(dict):
 
     def setdefault(self, key, default=None):
         assert self._assert_invariants()
-        if dict.__contains__(self, key):
+        if not dict.__contains__(self, key):
             self[key] = default
         assert self._assert_invariants()
         return self[key]
@@ -522,15 +526,15 @@ class SmallOrderedDict(dict):
                 while len(self) > self._maxsize:
                     dict.popitem(self)
             else:
-                for k, v, in otherdict.iteritems():
+                for k, v, in otherdict.items():
                     if len(self) == self._maxsize:
                         break
                     dict.__setitem__(self, k, v)
-            self._lru = dict.keys(self)
+            self._lru = list(dict.keys(self))
             assert self._assert_invariants()
             return self
       
-        for k in otherdict.iterkeys():
+        for k in otherdict:
             if dict.__contains__(self, k):
                 self._lru.remove(k)
         self._lru.extend(otherdict.keys())
@@ -538,7 +542,8 @@ class SmallOrderedDict(dict):
 
         over = len(self) - self._maxsize
         if over > 0:
-            map(dict.__delitem__, [self]*over, self._lru[:over])
+            for k in self._lru[:over]:
+                dict.__delitem__(self, k)
             del self._lru[:over]
 
         assert self._assert_invariants()
