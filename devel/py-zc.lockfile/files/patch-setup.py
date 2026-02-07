--- setup.py.orig	2023-02-28 07:30:06 UTC
+++ setup.py
@@ -50,7 +50,6 @@ setup(
     package_dir={'': 'src'},
     namespace_packages=['zc'],
     python_requires='>=3.7',
-    install_requires='setuptools',
     extras_require=dict(
         test=[
             'zope.testing',
