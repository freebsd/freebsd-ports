--- zope/interface/adapter.py.orig	2007-03-01 14:45:32.000000000 +0800
+++ zope/interface/adapter.py	2009-10-17 13:00:44.000000000 +0800
@@ -38,14 +38,14 @@
 
 # The registrations are of the form:
 
-#   {(subscription, with, name, specification) -> factories}
+#   {(subscription, _with, name, specification) -> factories}
 
 # where:
 
 #   'subscription' is a flag indicating if this registration is for
 #   subscription adapters.
 
-#   'with' is a tuple of specs that is non-empty only in the case
+#   '_with' is a tuple of specs that is non-empty only in the case
 #   of multi-adapters.  
 
 #   'name' is a unicode adapter name.  Unnamed adapters have an empty
@@ -68,7 +68,7 @@
 
 # For multiple adapters:
 #
-# {(specification, order) -> {name -> {with -> object}}}
+# {(specification, order) -> {name -> {_with -> object}}}
 
 # For single subscription adapters:
 #
@@ -76,7 +76,7 @@
 
 # For multiple-subscription adapters:
 #
-# {('s', specification, order) -> {with -> tuple([object])}}
+# {('s', specification, order) -> {_with -> tuple([object])}}
 
 
 from __future__ import generators
@@ -193,29 +193,30 @@
                 #     or ('s', specification, order)
                 subscription = key[0] == 's'
                 if subscription:
-                    oldwithobs = implied.get(key)
-                    if not oldwithobs:
-                        oldwithobs = implied[key] = {}
+                    old_withobs = implied.get(key)
+                    if not old_withobs:
+                        old_withobs = implied[key] = {}
                         
-                    # v is {with -> tuple([object])}
-                    for with, objects in v.iteritems():
-                        oldwithobs[with] = oldwithobs.get(with, ()) + objects
+                    # v is {_with -> tuple([object])}
+                    for _with, objects in v.iteritems():
+                        old_withobs[_with] = old_withobs.get(_with, ()) + \
+                            objects
                     
                 else:
                     oldbyname = implied.get(key)
                     if not oldbyname:
                         implied[key] = oldbyname = {}
 
-                    # v is {name -> {with -> ?}}
-                    for name, withobs in v.iteritems():
-                        oldwithobs = oldbyname.get(name)
-                        if not oldwithobs:
-                            oldwithobs = oldbyname[name] = {}
+                    # v is {name -> {_with -> ?}}
+                    for name, _withobs in v.iteritems():
+                        old_withobs = oldbyname.get(name)
+                        if not old_withobs:
+                            old_withobs = oldbyname[name] = {}
 
-                        # withobs is {with -> object}
-                        oldwithobs.update(withobs)
+                        # _withobs is {_with -> object}
+                        old_withobs.update(_withobs)
 
-        # Now flatten with mappings to tuples
+        # Now flatten _with mappings to tuples
         for key, v in implied.iteritems():
             if isinstance(key, tuple):
                 if key[0] == 's':
@@ -226,9 +227,9 @@
                     byname = v
                     for name, value in byname.iteritems():
                         if isinstance(value, dict):
-                            # We have {with -> value}
-                            # convert it to sorted [(with, value]
-                            byname[name] = orderwith(value)
+                            # We have {_with -> value}
+                            # convert it to sorted [(_with, value]
+                            byname[name] = order_with(value)
 
         self.get = implied.get
 
@@ -260,24 +261,24 @@
     def unsubscribe(self, dependent):
         del self.dependents[dependent]
 
-    def _adaptTo(self, specification, object, name='', with=()):
+    def _adaptTo(self, specification, object, name='', _with=()):
         if object is None:
             try:
-                del self.adapters[False, tuple(with), name, specification]
+                del self.adapters[False, tuple(_with), name, specification]
             except KeyError:
                 pass
         else:
-            self.adapters[False, tuple(with), name, specification
+            self.adapters[False, tuple(_with), name, specification
                           ] = object
 
         self.dirty()
 
-    def _subscriptionAdaptTo(self, specification, object, with=()):
+    def _subscriptionAdaptTo(self, specification, object, _with=()):
         if object is None:
             raise TypeError, ("Unregistering subscription adapters" 
                               " isn't implemented")
 
-        key = (True, tuple(with), '', specification)
+        key = (True, tuple(_with), '', specification)
         self.adapters[key] = self.adapters.get(key, ()) + (object, )
         self.dirty()
 
@@ -287,26 +288,26 @@
     def __repr__(self):
         return '<%s(%s)>' % (self.__class__.__name__, self.spec())
 
-def orderwith(bywith):
+def order_with(by_with):
 
-    # Convert {with -> adapter} to withs, [(with, value)]
+    # Convert {_with -> adapter} to _withs, [(_with, value)]
     # such that there are no i, j, i < j, such that
-    #           withs[j][0] extends withs[i][0].
+    #           _withs[j][0] extends _withs[i][0].
 
-    withs = []
-    for with, value in bywith.iteritems():
-        for i, (w, v) in enumerate(withs):
-            if withextends(with, w):
-                withs.insert(i, (with, value))
+    _withs = []
+    for _with, value in by_with.iteritems():
+        for i, (w, v) in enumerate(_withs):
+            if _withextends(_with, w):
+                _withs.insert(i, (_with, value))
                 break
         else:
-            withs.append((with, value))
+            _withs.append((_with, value))
             
-    return withs
+    return _withs
     
 
-def withextends(with1, with2):
-    for spec1, spec2 in zip(with1, with2):
+def _withextends(_with1, _with2):
+    for spec1, spec2 in zip(_with1, _with2):
         if spec1.extends(spec2):
             return True
         if spec1 != spec2:
@@ -362,7 +363,7 @@
 
         # Multi adapter
 
-        with = required[1:]
+        _with = required[1:]
         key = provided, order
 
         for surrogate in self.get(required[0]), self._default:
@@ -370,8 +371,8 @@
             if not byname:
                 continue
 
-            bywith = byname.get(name)
-            if not bywith:
+            by_with = byname.get(name)
+            if not by_with:
                 continue
 
             # Selecting multi-adapters is not just a matter of matching the
@@ -381,10 +382,10 @@
 
             # `best` carries the rank and value of the best found adapter.
             best = None
-            for rwith, value in bywith:
+            for r_with, value in by_with:
                 # the `rank` describes how well the found adapter matches.
                 rank = []
-                for rspec, spec in zip(rwith, with):
+                for rspec, spec in zip(r_with, _with):
                     if not spec.isOrExtends(rspec):
                         break # This one is no good
                     # Determine the rank of this particular specification.
@@ -455,16 +456,16 @@
         
         # Multi
         key = 's', provided, order
-        with = required[1:]
+        _with = required[1:]
         result = []
         
         for surrogate in self.get(required[0]), self._default:
-            bywith = surrogate.get(key)
-            if not bywith:
+            by_with = surrogate.get(key)
+            if not by_with:
                 continue
 
-            for rwith, values in bywith:
-                for rspec, spec in zip(rwith, with):
+            for r_with, values in by_with:
+                for rspec, spec in zip(r_with, _with):
                     if not spec.isOrExtends(rspec):
                         break # This one is no good
                 else:
@@ -536,22 +537,22 @@
 
     def register(self, required, provided, name, value):
         if required:
-            with = []
+            _with = []
             for iface in required[1:]:
                 if iface is None:
                     iface = Interface
-                with.append(iface)
-            with = tuple(with)
+                _with.append(iface)
+            _with = tuple(_with)
             required = self.get(required[0])
         else:
-            with = ()
+            _with = ()
             required = self._null
         
         if not isinstance(name, basestring):
             raise TypeError("The name provided to provideAdapter "
                             "must be a string or unicode")
 
-        required._adaptTo(provided, value, unicode(name), with)
+        required._adaptTo(provided, value, unicode(name), _with)
 
     def lookupAll(self, required, provided):
         order = len(required)
@@ -584,7 +585,7 @@
 
         # Multi adapter
 
-        with = required[1:]
+        _with = required[1:]
         key = provided, order
         first = ()
 
@@ -593,16 +594,16 @@
             if not byname:
                 continue
 
-            for name, bywith in byname.iteritems():
-                if not bywith or name in first:
+            for name, by_with in byname.iteritems():
+                if not by_with or name in first:
                     continue
 
                 # See comments on lookup() above
                 best  = None
-                for rwith, value in bywith:
+                for r_with, value in by_with:
                     # the `rank` describes how well the found adapter matches.
                     rank = []
-                    for rspec, spec in zip(rwith, with):
+                    for rspec, spec in zip(r_with, _with):
                         if not spec.isOrExtends(rspec):
                             break # This one is no good
                         # Determine the rank of this particular specification.
@@ -622,19 +623,19 @@
 
     def subscribe(self, required, provided, value):
         if required:
-            required, with = self.get(required[0]), tuple(required[1:])
+            required, _with = self.get(required[0]), tuple(required[1:])
         else:
             required = self._null
-            with = ()
+            _with = ()
 
         if provided is None:
             provided = Null
             
-        required._subscriptionAdaptTo(provided, value, with)
+        required._subscriptionAdaptTo(provided, value, _with)
 
-def mextends(with, rwith):
-    if len(with) == len(rwith):
-        for w, r in zip(with, rwith):
+def mextends(_with, r_with):
+    if len(_with) == len(r_with):
+        for w, r in zip(_with, r_with):
             if not w.isOrExtends(r):
                 break
         else:
@@ -657,19 +658,19 @@
         # TODO: Backward compatibility
         # BBB ? Don't need to handle 3-tuples some day
         try:
-            (subscription, with, name, target) = key
+            (subscription, _with, name, target) = key
         except ValueError:
-            (with, name, target) = key
+            (_with, name, target) = key
             subscription = False
 
         if subscription:
-            if with:
-                _add_multi_sub_adapter(with, target, multi, value)
+            if _with:
+                _add_multi_sub_adapter(_with, target, multi, value)
             else:
                 _add_named_sub_adapter(target, implied, value)
         else:
-            if with:
-                _add_multi_adapter(with, name, target, target, multi,
+            if _with:
+                _add_multi_adapter(_with, name, target, target, multi,
                                    registered, value)
             else:
                 _add_named_adapter(target, target, name, implied,
@@ -699,21 +700,21 @@
             _add_named_adapter(b, provided, name, implied,
                                registered, value)
 
-def _add_multi_adapter(with, name, target, provided, implied,
+def _add_multi_adapter(_with, name, target, provided, implied,
                        registered, object):
 
-    ikey = target, (len(with) + 1)
+    ikey = target, (len(_with) + 1)
     byname = implied.get(ikey)
     if not byname:
         byname = implied[ikey] = {}
 
-    bywith = byname.get(name)
-    if not bywith:
-        bywith = byname[name] = {}
+    by_with = byname.get(name)
+    if not by_with:
+        by_with = byname[name] = {}
 
     
-    rkey = ikey, name, with # The full key has all 4
-    if (with not in bywith
+    rkey = ikey, name, _with # The full key has all 4
+    if (_with not in by_with
         or
         (rkey not in registered or registered[rkey].extends(provided))
         ):
@@ -721,10 +722,10 @@
         # general interface that is closer provided than what we had
         # before
         registered[rkey] = provided
-        bywith[with] = object
+        by_with[_with] = object
 
     for b in target.__bases__:
-        _add_multi_adapter(with, name, b, provided, implied,
+        _add_multi_adapter(_with, name, b, provided, implied,
                            registered, object)
 
 def _add_named_sub_adapter(target, implied, objects):
@@ -734,13 +735,13 @@
     for b in target.__bases__:
         _add_named_sub_adapter(b, implied, objects)
 
-def _add_multi_sub_adapter(with, target, implied, objects):
-    key = 's', target, (len(with) + 1)
-    bywith = implied.get(key)
-    if not bywith:
-        bywith = implied[key] = {}
+def _add_multi_sub_adapter(_with, target, implied, objects):
+    key = 's', target, (len(_with) + 1)
+    by_with = implied.get(key)
+    if not by_with:
+        by_with = implied[key] = {}
 
-    bywith[with] = bywith.get(with, ()) + objects
+    by_with[_with] = by_with.get(_with, ()) + objects
 
     for b in target.__bases__:
-        _add_multi_sub_adapter(with, b, implied, objects)
+        _add_multi_sub_adapter(_with, b, implied, objects)
