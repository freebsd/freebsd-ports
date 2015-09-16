--- scripts.orig/Expect.py	2015-01-23 13:16:01.000000000 +0000
+++ scripts/Expect.py	2015-01-23 13:21:06.526614131 +0000
@@ -484,7 +484,7 @@
         global processes
         del processes[self.p.pid]
         self.p = None
-        self.r.join()
+        self.r.join(timeout)
         # Simulate a match on EOF
         self.buf = self.r.getbuf()
         self.before = self.buf
