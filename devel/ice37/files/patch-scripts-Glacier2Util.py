--- scripts/Glacier2Util.py.orig	2022-01-15 23:22:20 UTC
+++ scripts/Glacier2Util.py
@@ -17,10 +17,13 @@ class Glacier2Router(ProcessFromBinDir, ProcessIsRelea
         return self.exe + "_32" if current.config.buildPlatform == "ppc" else self.exe
 
     def setup(self, current):
+        glacier2router = self.getMapping(current).getCommandLine(current, self, self.exe, "")
+        if not os.path.exists(self.exe) and os.path.exists("%%LOCALBASE%%/bin/glacier2router"):
+            self.exe = "%%LOCALBASE%%/bin/glacier2router"
         if self.passwords:
             path = os.path.join(current.testsuite.getPath(), "passwords")
             with open(path, "w") as file:
-                command = "\"%s\" %s" % (sys.executable,
+                command = "\"%s\" %s 2>/dev/null" % (sys.executable,
                                      os.path.abspath(os.path.join(toplevel, "scripts", "icehashpassword.py")))
 
                 #
