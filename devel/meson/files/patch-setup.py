--- setup.py.orig	2021-04-27 06:49:45 UTC
+++ setup.py
@@ -25,7 +25,7 @@ from setuptools import setup
 data_files = []
 if sys.platform != 'win32':
     # Only useful on UNIX-like systems
-    data_files = [('share/man/man1', ['man/meson.1']),
+    data_files = [('man/man1', ['man/meson.1']),
                   ('share/polkit-1/actions', ['data/com.mesonbuild.install.policy'])]
 
 setup(data_files=data_files,)
