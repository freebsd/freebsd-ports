--- setup.py.orig	2019-06-16 03:11:49 UTC
+++ setup.py
@@ -124,7 +124,7 @@ def setup_package():
             url=about['__uri__'],
             license=about['__license__'],
             ext_modules=ext_modules,
-            setup_requires=['wheel>=0.32.0,<0.33.0'],
+            setup_requires=[],
             install_requires=['cymem>=2.0.2,<2.1.0'],
             classifiers=[
                 'Environment :: Console',
