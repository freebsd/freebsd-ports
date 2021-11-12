Relax requirements for devel/py-setuptools_scm.  Python 3.5 is no longer
present in the Ports tree.

--- setup.py.orig	2021-08-06 12:04:59 UTC
+++ setup.py
@@ -111,7 +111,7 @@ setup(
                 'sadisplay'
             ],
     },
-    setup_requires=['setuptools_scm<6.0'],  # setuptools_scm>=6.0 doesn't support Python 3.5
+    setup_requires=['setuptools_scm'],  # setuptools_scm>=6.0 doesn't support Python 3.5
     use_scm_version=True,
 
     # If there are data files included in your packages that need to be
