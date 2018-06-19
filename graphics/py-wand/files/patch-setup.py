--- setup.py.orig	2016-10-22 05:27:48 UTC
+++ setup.py
@@ -35,7 +35,6 @@ else:
 setup(
     name='Wand',
     packages=['wand'],
-    data_files=[('', ['README.rst'])],
     version=VERSION,
     description='Ctypes-based simple MagickWand API binding for Python',
     long_description=readme(),
