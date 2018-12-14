--- analyzer/python/ikos/analyzer.py.orig	2018-12-14 07:13:50 UTC
+++ analyzer/python/ikos/analyzer.py
@@ -554,10 +554,10 @@ def clang(bc_path, cpp_path, colors=True
     # For #include <ikos/analyzer/intrinsic.hpp>
     cmd += ['-isystem', settings.INCLUDE_DIR]
 
-    if colors:
-        cmd.append('-fcolor-diagnostics')
-    else:
-        cmd.append('-fno-color-diagnostics')
+    #if colors:
+    #    cmd.append('-fcolor-diagnostics')
+    #else:
+    #    cmd.append('-fno-color-diagnostics')
 
     if cpp_path.endswith('.cpp'):
         cmd.append('-std=c++14')  # available because clang >= 4.0
