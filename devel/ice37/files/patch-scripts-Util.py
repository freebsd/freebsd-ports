--- scripts/Util.py.orig	2022-01-15 23:22:20 UTC
+++ scripts/Util.py
@@ -263,7 +263,7 @@ class Platform(object):
         elif Mapping.getByName("cpp"):
             cwd = Mapping.getByName("cpp").getPath()
 
-        output = run('make print V="{0}"'.format(" ".join(variables.keys())), cwd=cwd)
+        output = run('gmake print V="{0}"'.format(" ".join(variables.keys())), cwd=cwd)
         for l in output.split("\n"):
             match = re.match(r'^.*:.*: (.*) = (.*)', l)
             if match and match.group(1):
@@ -348,6 +348,29 @@ class AIX(Platform):
     def getInstallDir(self):
         return "/opt/freeware"
 
+class FreeBSD(Platform):
+
+    def __init__(self):
+        self.nugetPackageCache = None
+        self._hasNodeJS = None
+        self._hasSwift = None
+
+    def hasOpenSSL(self):
+        return True
+
+    def getSliceDir(self, iceDir):
+        installDir = self.getInstallDir(mapping, current)
+        return os.path.join(installDir, "slice")
+
+    def getDefaultExe(self, name, config):
+        if name == "icebox":
+            if config.cpp11:
+                name += "++11"
+        return name
+
+    def canRun(self, mapping, current):
+        return Platform.canRun(self, mapping, current)
+
 class Linux(Platform):
 
     def __init__(self):
@@ -1443,7 +1466,7 @@
         # Look for slice2py installed by pip if not found in the bin directory
         #
         if self.exe == "slice2py":
-            translator = self.getMapping(current).getCommandLine(current, self, self.getExe(current), "")
+            translator = self.getMapping(current).getCommandLine(current, self, "%%LOCALBASE%%/bin/slice2py", "")
             if not os.path.exists(translator):
                 translator = sys.executable + " -m slice2py"
             return (translator + " " + args).strip()
@@ -4059,6 +4082,8 @@ if sys.platform == "darwin":
     platform = Darwin()
 elif sys.platform.startswith("aix"):
     platform = AIX()
+elif sys.platform.startswith("freebsd"):
+    platform = FreeBSD()
 elif sys.platform.startswith("linux") or sys.platform.startswith("gnukfreebsd"):
     platform = Linux()
 elif sys.platform == "win32" or sys.platform[:6] == "cygwin":
