--- setup.py.orig	2021-08-20 05:54:02 UTC
+++ setup.py
@@ -33,5 +33,5 @@ setup(
   url = 'http://openEMS.de',
   packages=["CSXCAD", ],
   package_data={'CSXCAD': ['*.pxd']},
-  ext_modules = cythonize(extensions)
+  ext_modules = cythonize(extensions, language_level=3)
  )
