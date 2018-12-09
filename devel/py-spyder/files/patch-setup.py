--- setup.py.orig	2018-03-13 19:57:09 UTC
+++ setup.py
@@ -291,7 +291,7 @@ install_requires = [
     'numpydoc',
     # Packages for pyqt5 are only available in
     # Python 3
-    'pyqt5<5.10;python_version>="3"',
+    #'pyqt5<5.10;python_version>="3"',
     # This is only needed for our wheels on Linux.
     # See issue #3332
     'pyopengl;platform_system=="Linux"'
