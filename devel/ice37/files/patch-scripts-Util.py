--- scripts/Util.py.orig	2018-08-27 01:10:47 UTC
+++ scripts/Util.py
@@ -82,7 +82,7 @@ class Platform:
 
     def parseBuildVariables(self, variables):
         # Run make to get the values of the given variables
-        output = run('make print V="{0}"'.format(" ".join(variables.keys())), cwd = toplevel)
+        output = run('gmake print V="{0}"'.format(" ".join(variables.keys())), cwd = toplevel)
         for l in output.split("\n"):
             match = re.match(r'^.*:.*: (.*) = (.*)', l)
             if match and match.group(1):
@@ -199,6 +199,46 @@ class AIX(Platform):
     def hasOpenSSL(self):
         return True
 
+class FreeBSD(Platform):
+
+    def __init__(self):
+        Platform.__init__(self)
+
+    def getFilters(self, config):
+        filters = Platform.getFilters(self, config)
+        #filters = (filters[0], filters[1] + ["Slice/*"])
+        return filters
+
+    def hasOpenSSL(self):
+        return True
+
+    def getBinSubDir(self, mapping, process, current):
+        buildPlatform = current.driver.configs[mapping].buildPlatform
+        return "bin"
+
+    def getLibSubDir(self, mapping, process, current):
+        buildPlatform = current.driver.configs[mapping].buildPlatform
+
+        # PHP module is always installed in the lib directory for the default build platform
+        if isinstance(mapping, PhpMapping) and buildPlatform == self.getDefaultBuildPlatform():
+            return "lib"
+        return "lib"
+
+    def getBuildSubDir(self, name, current):
+        return os.path.join("build", current.config.buildPlatform, current.config.buildConfig)
+
+    def getSliceDir(self, iceDir):
+        return os.path.join(iceDir, "slice")
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
@@ -434,6 +474,8 @@ if sys.platform == "darwin":
     platform = Darwin()
 elif sys.platform.startswith("aix"):
     platform = AIX()
+elif sys.platform.startswith("freebsd"):
+    platform = FreeBSD()
 elif sys.platform.startswith("linux") or sys.platform.startswith("gnukfreebsd"):
     platform = Linux()
 elif sys.platform == "win32" or sys.platform[:6] == "cygwin":
@@ -1333,8 +1375,8 @@ class SliceTranslator(ProcessFromBinDir,
                 return translator + " " + args if args else translator
             elif isinstance(platform, Windows):
                 return os.path.join(os.path.dirname(sys.executable), "Scripts", "slice2py.exe")
-            elif os.path.exists("/usr/local/bin/slice2py"):
-                return "/usr/local/bin/slice2py"
+            elif os.path.exists("%%LOCALBASE%%/bin/slice2py"):
+                return "%%LOCALBASE%%/bin/slice2py " + args if args else "%%LOCALBASE%%/bin/slice2py "
             else:
                 import slice2py
                 return sys.executable + " " + os.path.normpath(
