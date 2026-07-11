--- setup.py.orig	2021-03-17 20:17:30 UTC
+++ setup.py
@@ -28,7 +28,8 @@
 #  - git commit -a -m "post-release"
 #  - git push
 
-from imp import load_source
+import importlib.machinery
+import importlib.util
 from os import path
 try:
     # setuptools supports bdist_wheel
@@ -55,7 +56,13 @@ with open('README.rst') as fp:
 with open('README.rst') as fp:
     LONG_DESCRIPTION = fp.read()
 
-ptrace = load_source("version", path.join("ptrace", "version.py"))
+filepath = path.join("ptrace", "version.py")
+loader = importlib.machinery.SourceFileLoader("version", filepath)
+spec = importlib.util.spec_from_file_location(
+            "version", filepath, loader=loader)
+module = importlib.util.module_from_spec(spec)
+loader.exec_module(module)
+ptrace = module
 PACKAGES = {}
 for name in MODULES:
     PACKAGES[name] = name.replace(".", "/")
