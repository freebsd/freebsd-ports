--- python/mozbuild/mozbuild/pythonutil.py.orig	2021-03-15 15:52:37 UTC
+++ python/mozbuild/mozbuild/pythonutil.py
@@ -81,7 +81,7 @@ def _find_python_executable(major):
         names = ['python%d' % major]
 
         # Look for `pythonX.Y` down to our minimum version.
-        for minor in range(9, min_version.version[1] - 1, -1):
+        for minor in range(20, min_version.version[1] - 1, -1):
             names.append('python%d.%d' % (major, minor))
 
         for name in names:
