--- scripts/Util.py.orig	2019-02-11 16:48:19.076747000 +0100
+++ scripts/Util.py	2019-02-11 19:16:32.768690000 +0100
@@ -232,7 +232,7 @@
         elif Mapping.getByName("cpp"):
             cwd = Mapping.getByName("cpp").getPath()
 
-        output = run('make print V="{0}"'.format(" ".join(variables.keys())), cwd=cwd)
+        output = run('gmake print V="{0}"'.format(" ".join(variables.keys())), cwd=cwd)
         for l in output.split("\n"):
             match = re.match(r'^.*:.*: (.*) = (.*)', l)
             if match and match.group(1):
@@ -304,6 +304,27 @@
     def hasOpenSSL(self):
         return True
 
+class FreeBSD(Platform):
+
+    def __init__(self):
+        self.nugetPackageCache = None
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
@@ -1374,13 +1402,13 @@
             if os.path.exists(translator):
                 return translator + " " + args if args else translator
             elif isinstance(platform, Windows):
-                return os.path.join(os.path.dirname(sys.executable), "Scripts", "slice2py.exe")
+                return os.path.join(os.path.dirname(sys.executable), "Scripts", "slice2py.exe") + " " + args if args else translator
             elif os.path.exists("/usr/local/bin/slice2py"):
-                return "/usr/local/bin/slice2py"
+                return "/usr/local/bin/slice2py" + " " + args if args else translator
             else:
                 import slice2py
                 return sys.executable + " " + os.path.normpath(
-                            os.path.join(slice2py.__file__, "..", "..", "..", "..", "bin", "slice2py"))
+                            os.path.join(slice2py.__file__, "..", "..", "..", "..", "bin", "slice2py")) + " " + args if args else translator
         else:
             return Process.getCommandLine(self, current, args)
 
@@ -3786,6 +3807,8 @@
     platform = Darwin()
 elif sys.platform.startswith("aix"):
     platform = AIX()
+elif sys.platform.startswith("freebsd"):
+    platform = FreeBSD()
 elif sys.platform.startswith("linux") or sys.platform.startswith("gnukfreebsd"):
     platform = Linux()
 elif sys.platform == "win32" or sys.platform[:6] == "cygwin":
