Relax requirements for devel/py-setuptools_scm.  Python 3.5 is no longer
present in the Ports tree.

--- setup.py.orig	2022-08-31 00:23:56 UTC
+++ setup.py
@@ -109,7 +109,7 @@ setup(
     # for example:
     # $ pip install -e .[dev,test]
     extras_require={'doc': read_requirements('doc')},
-    setup_requires=['setuptools_scm<6.0'],
+    setup_requires=['setuptools_scm'],
     use_scm_version=True,
 
     # If there are data files included in your packages that need to be
