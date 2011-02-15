--- setup.py.orig	2011-02-10 18:06:05.000000000 +0100
+++ setup.py	2011-02-10 18:06:15.000000000 +0100
@@ -260,29 +260,6 @@
 py_25 = sys.version_info[0] > 2 or (sys.version_info[0] == 2 and sys.version_info[1] >= 5)
 py_26 = sys.version_info[0] > 2 or (sys.version_info[0] == 2 and sys.version_info[1] >= 6)
 
-try:
-    # If setuptools is installed, then we'll add setuptools-specific arguments
-    # to the setup args.
-    import setuptools #@UnusedImport
-except ImportError:
-    pass
-else:
-    ## dependencies
-    setup_args['install_requires'] = [
-        'twisted >= 2.0.0',
-        'Jinja2 >= 2.1',
-    ]
-    # Python-2.6 and up includes json
-    if not py_26:
-        setup_args['install_requires'].append('simplejson')
-
-    # Python-2.6 and up includes a working A sqlite (py25's is broken)
-    if not py_26:
-        setup_args['install_requires'].append('pysqlite')
-
-    if os.getenv('NO_INSTALL_REQS'):
-        setup_args['install_requires'] = None
-
 setup(**setup_args)
 
 # Local Variables:
