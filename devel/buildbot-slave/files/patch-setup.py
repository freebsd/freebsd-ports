--- setup.py.orig	2010-08-09 10:54:05.000000000 +0800
+++ setup.py	2010-08-09 11:06:44.000000000 +0800
@@ -58,22 +58,4 @@
 if sys.platform == "win32":
     setup_args['zip_safe'] = False
 
-try:
-    # If setuptools is installed, then we'll add setuptools-specific arguments
-    # to the setup args.
-    import setuptools #@UnusedImport
-except ImportError:
-    setup_args['scripts'] = [
-        'bin/buildslave'
-    ]
-else:
-    setup_args['install_requires'] = [
-        'twisted >= 2.0.0',
-    ]
-    setup_args['entry_points'] = {
-        'console_scripts': [
-            'buildslave = buildslave.scripts.runner:run',
-        ],
-    }
-
 setup(**setup_args)
