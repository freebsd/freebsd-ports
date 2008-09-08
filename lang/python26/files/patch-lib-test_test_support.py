--- Lib/test/test_support.py.orig	2008-01-27 01:24:44.000000000 +0000
+++ Lib/test/test_support.py	2008-08-30 10:16:13.000000000 +0100
@@ -33,6 +33,7 @@
 use_resources = None     # Flag set to [] by regrtest.py
 max_memuse = 0           # Disable bigmem tests (they will still be run with
                          # small sizes, to make sure they work.)
+real_max_memuse = 0
 
 # _original_stdout is meant to hold stdout at the time regrtest began.
 # This may be "the real" stdout, or IDLE's emulation of stdout, or whatever.
@@ -323,6 +324,7 @@
 _1M = 1024*1024
 _1G = 1024 * _1M
 _2G = 2 * _1G
+_4G = 4 * _1G
 
 # Hack to get at the maximum value an internal index can take.
 class _Dummy:
@@ -333,6 +335,7 @@
 def set_memlimit(limit):
     import re
     global max_memuse
+    global real_max_memuse
     sizes = {
         'k': 1024,
         'm': _1M,
@@ -344,6 +347,7 @@
     if m is None:
         raise ValueError('Invalid memory limit %r' % (limit,))
     memlimit = int(float(m.group(1)) * sizes[m.group(3).lower()])
+    real_max_memuse = memlimit
     if memlimit > MAX_Py_ssize_t:
         memlimit = MAX_Py_ssize_t
     if memlimit < _2G - 1:
@@ -389,6 +393,27 @@
         return wrapper
     return decorator
 
+def precisionbigmemtest(size, memuse, overhead=5*_1M):
+    def decorator(f):
+        def wrapper(self):
+            if not real_max_memuse:
+                maxsize = 5147
+            else:
+                maxsize = size
+
+                if real_max_memuse and real_max_memuse < maxsize * memuse:
+                    if verbose:
+                        sys.stderr.write("Skipping %s because of memory "
+                                         "constraint\n" % (f.__name__,))
+                    return
+
+            return f(self, maxsize)
+        wrapper.size = size
+        wrapper.memuse = memuse
+        wrapper.overhead = overhead
+        return wrapper
+    return decorator
+
 def bigaddrspacetest(f):
     """Decorator for tests that fill the address space."""
     def wrapper(self):
