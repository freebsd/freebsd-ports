--- setup.py.orig	2024-11-11 11:50:45 UTC
+++ setup.py
@@ -56,4 +56,4 @@ setup(name='fugashi', 
           'unidic': ['unidic'],
           'unidic-lite': ['unidic-lite'],
       },
-      setup_requires=['wheel', 'Cython~=3.0.11', 'setuptools_scm'])
+      setup_requires=['wheel', 'Cython>=3.0.11', 'setuptools_scm'])
