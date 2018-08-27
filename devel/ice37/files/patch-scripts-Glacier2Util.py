--- scripts/Glacier2Util.py.orig	2018-08-27 01:10:47 UTC
+++ scripts/Glacier2Util.py
@@ -19,10 +19,13 @@ class Glacier2Router(ProcessFromBinDir, 
         self.passwords = passwords
 
     def setup(self, current):
+        glacier2router = self.getMapping(current).getCommandLine(current, self, self.exe, "")
+        if not os.path.exists(self.exe) and os.path.exists("/usr/local/bin/glacier2router"):
+            self.exe = "/usr/local/bin/glacier2router"
         if self.passwords:
             path = os.path.join(current.testsuite.getPath(), "passwords")
             with open(path, "w") as file:
-                command = "\"%s\" %s" % (sys.executable,
+                command = "\"%s\" %s 2>/dev/null" % (sys.executable,
                                      os.path.abspath(os.path.join(toplevel, "scripts", "icehashpassword.py")))
 
                 #
