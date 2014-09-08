--- scripts/Expect.py.orig	2013-03-11 15:19:47.000000000 +0000
+++ scripts/Expect.py	2014-09-08 22:32:43.000000000 +0000
@@ -461,7 +461,7 @@
             if win32 and self.exitstatus != 0 and self.killed is not None:
                 self.exitstatus = -self.killed
             self.p = None
-            self.r.join()
+            self.r.join(timeout)
             # Simulate a match on EOF
             self.buf = self.r.getbuf()
             self.before = self.buf
