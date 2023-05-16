--- setup.py.orig	2023-05-16 05:00:53 UTC
+++ setup.py
@@ -1,10 +1,18 @@
 from setuptools import Extension, setup
 import sys
+import platform
 
 with open("README.md", "r") as fh:
     long_description = fh.read()
 
-static_libraries   = ['aplib64']
+if platform.system() == 'FreeBSD':
+    if platform.machine() == 'i386':
+        static_libraries   = ['aplib32']
+    elif platform.machine() == 'amd64':
+        static_libraries   = ['aplib64']
+else:
+    static_libraries   = ['aplib64']
+
 static_lib_dir     = 'lib'
 libraries          = []
 library_dirs       = ['lib']
