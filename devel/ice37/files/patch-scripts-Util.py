--- scripts/Util.py.orig	2024-04-27 11:12:29 UTC
+++ scripts/Util.py
@@ -259,7 +259,7 @@ class Platform(object):
         elif Mapping.getByName("cpp"):
             cwd = Mapping.getByName("cpp").getPath()
 
-        output = run('make print V="{0}"'.format(" ".join(variables.keys())), cwd=cwd)
+        output = run('gmake print V="{0}"'.format(" ".join(variables.keys())), cwd=cwd)
         for l in output.split("\n"):
             match = re.match(r'^.*:.*: (.*) = (.*)', l)
             if match and match.group(1):
@@ -344,6 +344,29 @@ class AIX(Platform):
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
@@ -1441,7 +1464,7 @@ class SliceTranslator(ProcessFromBinDir, ProcessIsRele
         # Look for slice2py installed by pip if not found in the bin directory
         #
         if self.exe == "slice2py":
-            translator = self.getMapping(current).getCommandLine(current, self, self.getExe(current), "")
+            translator = self.getMapping(current).getCommandLine(current, self, "%%LOCALBASE%%/bin/slice2py", "")
             if not os.path.exists(translator):
                 translator = sys.executable + " -m slice2py"
             return (translator + " " + args).strip()
@@ -3909,6 +3932,8 @@ if sys.platform == "darwin":
     platform = Darwin()
 elif sys.platform.startswith("aix"):
     platform = AIX()
+elif sys.platform.startswith("freebsd"):
+    platform = FreeBSD()
 elif sys.platform.startswith("linux") or sys.platform.startswith("gnukfreebsd"):
     platform = Linux()
 elif sys.platform == "win32" or sys.platform[:6] == "cygwin":
