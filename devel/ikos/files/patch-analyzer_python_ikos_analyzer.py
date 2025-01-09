--- analyzer/python/ikos/analyzer.py.orig	2024-12-31 23:34:34 UTC
+++ analyzer/python/ikos/analyzer.py
@@ -703,10 +703,10 @@ def clang(
     if machine_flags:
         cmd += ['-m%s' % m for m in machine_flags]
 
-    if colors:
-        cmd.append('-fcolor-diagnostics')
-    else:
-        cmd.append('-fno-color-diagnostics')
+    #if colors:
+    #    cmd.append('-fcolor-diagnostics')
+    #else:
+    #    cmd.append('-fno-color-diagnostics')
 
     if path_ext(cpp_path) in cpp_extensions:
         cmd.append('-std=c++17')  # available because clang >= 7.0
