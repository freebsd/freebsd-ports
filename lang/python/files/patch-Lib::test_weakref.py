--- Lib/test/test_weakref.py.orig	Tue Jul 15 06:37:17 2003
+++ Lib/test/test_weakref.py	Fri Nov 21 11:39:53 2003
@@ -299,6 +299,211 @@
             self.fail("exception not properly restored")
 
 
+    def test_callback_in_cycle_1(self):
+        import gc
+
+        class J(object):
+            pass
+
+        class II(object):
+            def acallback(self, ignore):
+                self.J
+
+        I = II()
+        I.J = J
+        I.wr = weakref.ref(J, I.acallback)
+
+        # Now J and II are each in a self-cycle (as all new-style class
+        # objects are, since their __mro__ points back to them).  I holds
+        # both a weak reference (I.wr) and a strong reference (I.J) to class
+        # J.  I is also in a cycle (I.wr points to a weakref that references
+        # I.acallback).  When we del these three, they all become trash, but
+        # the cycles prevent any of them from getting cleaned up immediately.
+        # Instead they have to wait for cyclic gc to deduce that they're
+        # trash.
+        #
+        # gc used to call tp_clear on all of them, and the order in which
+        # it does that is pretty accidental.  The exact order in which we
+        # built up these things manages to provoke gc into running tp_clear
+        # in just the right order (I last).  Calling tp_clear on II leaves
+        # behind an insane class object (its __mro__ becomes NULL).  Calling
+        # tp_clear on J breaks its self-cycle, but J doesn't get deleted
+        # just then because of the strong reference from I.J.  Calling
+        # tp_clear on I starts to clear I's __dict__, and just happens to
+        # clear I.J first -- I.wr is still intact.  That removes the last
+        # reference to J, which triggers the weakref callback.  The callback
+        # tries to do "self.J", and instances of new-style classes look up
+        # attributes ("J") in the class dict first.  The class (II) wants to
+        # search II.__mro__, but that's NULL.   The result was a segfault in
+        # a release build, and an assert failure in a debug build.
+        del I, J, II
+        gc.collect()
+
+    def test_callback_in_cycle_2(self):
+        import gc
+
+        # This is just like test_callback_in_cycle_1, except that II is an
+        # old-style class.  The symptom is different then:  an instance of an
+        # old-style class looks in its own __dict__ first.  'J' happens to
+        # get cleared from I.__dict__ before 'wr', and 'J' was never in II's
+        # __dict__, so the attribute isn't found.  The difference is that
+        # the old-style II doesn't have a NULL __mro__ (it doesn't have any
+        # __mro__), so no segfault occurs.  Instead it got:
+        #    test_callback_in_cycle_2 (__main__.ReferencesTestCase) ...
+        #    Exception exceptions.AttributeError:
+        #   "II instance has no attribute 'J'" in <bound method II.acallback
+        #       of <?.II instance at 0x00B9B4B8>> ignored
+
+        class J(object):
+            pass
+
+        class II:
+            def acallback(self, ignore):
+                self.J
+
+        I = II()
+        I.J = J
+        I.wr = weakref.ref(J, I.acallback)
+
+        del I, J, II
+        gc.collect()
+
+    def test_callback_in_cycle_3(self):
+        import gc
+
+        # This one broke the first patch that fixed the last two.  In this
+        # case, the objects reachable from the callback aren't also reachable
+        # from the object (c1) *triggering* the callback:  you can get to
+        # c1 from c2, but not vice-versa.  The result was that c2's __dict__
+        # got tp_clear'ed by the time the c2.cb callback got invoked.
+
+        class C:
+            def cb(self, ignore):
+                self.me
+                self.c1
+                self.wr
+
+        c1, c2 = C(), C()
+
+        c2.me = c2
+        c2.c1 = c1
+        c2.wr = weakref.ref(c1, c2.cb)
+
+        del c1, c2
+        gc.collect()
+
+    def test_callback_in_cycle_4(self):
+        import gc
+
+        # Like test_callback_in_cycle_3, except c2 and c1 have different
+        # classes.  c2's class (C) isn't reachable from c1 then, so protecting
+        # objects reachable from the dying object (c1) isn't enough to stop
+        # c2's class (C) from getting tp_clear'ed before c2.cb is invoked.
+        # The result was a segfault (C.__mro__ was NULL when the callback
+        # tried to look up self.me).
+
+        class C(object):
+            def cb(self, ignore):
+                self.me
+                self.c1
+                self.wr
+
+        class D:
+            pass
+
+        c1, c2 = D(), C()
+
+        c2.me = c2
+        c2.c1 = c1
+        c2.wr = weakref.ref(c1, c2.cb)
+
+        del c1, c2, C, D
+        gc.collect()
+
+    def test_callback_in_cycle_resurrection(self):
+        import gc
+
+        # Do something nasty in a weakref callback:  resurrect objects
+        # from dead cycles.  For this to be attempted, the weakref and
+        # its callback must also be part of the cyclic trash (else the
+        # objects reachable via the callback couldn't be in cyclic trash
+        # to begin with -- the callback would act like an external root).
+        # But gc clears trash weakrefs with callbacks early now, which
+        # disables the callbacks, so the callbacks shouldn't get called
+        # at all (and so nothing actually gets resurrected).
+
+        alist = []
+        class C(object):
+            def __init__(self, value):
+                self.attribute = value
+
+            def acallback(self, ignore):
+                alist.append(self.c)
+
+        c1, c2 = C(1), C(2)
+        c1.c = c2
+        c2.c = c1
+        c1.wr = weakref.ref(c2, c1.acallback)
+        c2.wr = weakref.ref(c1, c2.acallback)
+
+        def C_went_away(ignore):
+            alist.append("C went away")
+        wr = weakref.ref(C, C_went_away)
+
+        del c1, c2, C   # make them all trash
+        self.assertEqual(alist, [])  # del isn't enough to reclaim anything
+
+        gc.collect()
+        # c1.wr and c2.wr were part of the cyclic trash, so should have
+        # been cleared without their callbacks executing.  OTOH, the weakref
+        # to C is bound to a function local (wr), and wasn't trash, so that
+        # callback should have been invoked when C went away.
+        self.assertEqual(alist, ["C went away"])
+        # The remaining weakref should be dead now (its callback ran).
+        self.assertEqual(wr(), None)
+
+        del alist[:]
+        gc.collect()
+        self.assertEqual(alist, [])
+
+    def test_callbacks_on_callback(self):
+        import gc
+
+        # Set up weakref callbacks *on* weakref callbacks.
+        alist = []
+        def safe_callback(ignore):
+            alist.append("safe_callback called")
+
+        class C(object):
+            def cb(self, ignore):
+                alist.append("cb called")
+
+        c, d = C(), C()
+        c.other = d
+        d.other = c
+        callback = c.cb
+        c.wr = weakref.ref(d, callback)     # this won't trigger
+        d.wr = weakref.ref(callback, d.cb)  # ditto
+        external_wr = weakref.ref(callback, safe_callback)  # but this will
+        self.assert_(external_wr() is callback)
+
+        # The weakrefs attached to c and d should get cleared, so that
+        # C.cb is never called.  But external_wr isn't part of the cyclic
+        # trash, and no cyclic trash is reachable from it, so safe_callback
+        # should get invoked when the bound method object callback (c.cb)
+        # -- which is itself a callback, and also part of the cyclic trash --
+        # gets reclaimed at the end of gc.
+
+        del callback, c, d, C
+        self.assertEqual(alist, [])  # del isn't enough to clean up cycles
+        gc.collect()
+        self.assertEqual(alist, ["safe_callback called"])
+        self.assertEqual(external_wr(), None)
+
+        del alist[:]
+        gc.collect()
+        self.assertEqual(alist, [])
+
 class Object:
     def __init__(self, arg):
         self.arg = arg
