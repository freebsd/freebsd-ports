--- ./setup.py.orig	2012-06-07 14:17:23.000000000 +0400
+++ ./setup.py	2013-03-06 01:18:47.000000000 +0400
@@ -109,11 +109,8 @@
 install_requires.extend([
     "anyjson>=0.3.1",
     "kombu>=2.1.8,<2.2.0",
+    "python-dateutil != 2.0",
 ])
-if is_py3k:
-    install_requires.append("python-dateutil>=2.0")
-else:
-    install_requires.append("python-dateutil>=1.5,<2.0")
 
 py_version = sys.version_info
 is_jython = sys.platform.startswith("java")
