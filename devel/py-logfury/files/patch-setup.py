--- setup.py.orig	2021-10-21 05:05:21 UTC
+++ setup.py
@@ -72,6 +72,6 @@ setup(
     classifiers      = CLASSIFIERS,
     package_data     = {NAME: ['requirements.txt', 'LICENSE']},
 
-    setup_requires   = ['setuptools_scm<6.0'],  # setuptools_scm>=6.0 doesn't support Python 3.5
+    setup_requires   = ['setuptools_scm'],  # setuptools_scm>=6.0 doesn't support Python 3.5
     use_scm_version  = True,
 )  # yapf: disable
