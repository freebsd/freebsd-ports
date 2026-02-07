--- setup.py.orig	2024-10-19 12:39:56 UTC
+++ setup.py
@@ -80,8 +80,8 @@ class BuildQt(setuptools.Command):
 
     def find_executable(self, name):
         path = os.getenv("PATH").split(os.pathsep)
-        path.extend(["/usr/lib64/qt6/bin", "/usr/lib64/qt6/libexec",
-                     "/usr/lib/qt6/bin", "/usr/lib/qt6/libexec",
+        path.extend(["", "/usr/lib64/qt6/bin", "/usr/lib64/qt6/libexec", "%%LOCALBASE%%/libexec/qt6/",
+                     "/usr/lib/qt6/bin", "/usr/lib/qt6/libexec", "%%LOCALBASE%%/lib/qt6/bin",
                      "/usr/lib/x86_64-linux-gnu/qt6/bin", "/usr/lib/x86_64-linux-gnu/qt6/libexec"])
 
         os.environ["PATH"] = os.pathsep.join(path)
