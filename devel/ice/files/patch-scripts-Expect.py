--- scripts/Expect.py.orig	2019-08-12 19:54:18 UTC
+++ scripts/Expect.py
@@ -505,7 +505,7 @@ class Expect (object):
         global processes
         del processes[self.p.pid]
         self.p = None
-        self.r.join()
+        self.r.join(timeout)
         # Simulate a match on EOF
         self.buf = self.r.getbuf()
         self.before = self.buf
