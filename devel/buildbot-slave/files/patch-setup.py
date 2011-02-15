--- setup.py.orig	2011-02-10 18:18:31.000000000 +0100
+++ setup.py	2011-02-10 18:18:42.000000000 +0100
@@ -102,18 +102,4 @@
 if sys.platform == "win32":
     setup_args['zip_safe'] = False
 
-try:
-    # If setuptools is installed, then we'll add setuptools-specific arguments
-    # to the setup args.
-    import setuptools #@UnusedImport
-except ImportError:
-    pass
-else:
-    setup_args['install_requires'] = [
-        'twisted >= 2.0.0',
-    ]
-
-    if os.getenv('NO_INSTALL_REQS'):
-        setup_args['install_requires'] = None
-
 setup(**setup_args)
