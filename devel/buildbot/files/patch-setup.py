--- setup.py.orig	2009-02-19 00:08:42.135500043 +0800
+++ setup.py	2009-02-19 00:08:50.857400452 +0800
@@ -89,20 +89,6 @@
     'cmdclass': {'install_data': install_data_twisted},
     }
 
-try:
-    # If setuptools is installed, then we'll add setuptools-specific arguments
-    # to the setup args.
-    import setuptools
-except ImportError:
-    pass
-else:
-    setup_args['install_requires'] = ['twisted >= 2.0.0']
-    entry_points={
-        'console_scripts': [
-            'buildbot = buildbot.scripts.runner:run'
-            ]
-        },
-
 setup(**setup_args)
 
 # Local Variables:
