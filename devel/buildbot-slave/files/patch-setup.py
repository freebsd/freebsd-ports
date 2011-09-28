--- setup.py.orig	2011-06-20 11:58:27.000000000 +0800
+++ setup.py	2011-06-20 11:59:29.000000000 +0800
@@ -103,18 +103,4 @@
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
-        'twisted >= 8.0.0',
-    ]
-
-    if os.getenv('NO_INSTALL_REQS'):
-        setup_args['install_requires'] = None
-
 setup(**setup_args)
