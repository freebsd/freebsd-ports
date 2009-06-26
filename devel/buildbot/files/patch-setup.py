--- setup.py.orig	2009-03-03 01:13:03.000000000 +0800
+++ setup.py	2009-06-26 23:28:27.000000000 +0800
@@ -107,19 +107,6 @@
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
-            'buildbot = buildbot.scripts.runner:run'],
-        },
-
 setup(**setup_args)
 
 # Local Variables:
