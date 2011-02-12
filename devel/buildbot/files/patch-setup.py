--- setup.py.orig	2011-02-12 22:21:14.000000000 +0800
+++ setup.py	2011-02-12 22:23:41.000000000 +0800
@@ -251,34 +251,6 @@
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
-    entry_points={
-        'console_scripts': [
-            'buildbot = buildbot.scripts.runner:run'],
-        },
-
 setup(**setup_args)
 
 # Local Variables:
