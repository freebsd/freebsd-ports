--- setup.py.orig	Sun Nov 19 19:43:16 2006
+++ setup.py	Sun Nov 19 19:43:09 2006
@@ -2,7 +2,7 @@
 from distutils.core import setup, Extension
 
 magic_module = Extension('magic',
-    libraries = ['magic'],
+    libraries = ['magic', 'z'],
     library_dirs = ['./','../','../src','/usr/lib/'],
     include_dirs = ['./','../','../src','/usr/include/'],
     sources = ['py_magic.c'])
