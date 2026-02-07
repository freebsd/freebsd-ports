--- setup.py.orig	2023-03-31 01:40:17 UTC
+++ setup.py
@@ -30,7 +30,7 @@ setup(name='glom',
           'Documentation': 'https://glom.readthedocs.io/en/latest/',
       },
       packages=['glom', 'glom.test'],
-      install_requires=['boltons>=19.3.0', 'attrs', 'face==20.1.1'],
+      install_requires=['boltons>=19.3.0', 'attrs', 'face>=20.1.1'],
       extras_require={
           'yaml': ['PyYAML'],
       },
