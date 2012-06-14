--- setup.py.orig	2012-06-02 08:58:34.000000000 -0400
+++ setup.py	2012-06-02 08:58:58.000000000 -0400
@@ -279,34 +279,6 @@
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
-        'twisted >= 8.0.0',
-        'Jinja2 >= 2.1',
-        'sqlalchemy >= 0.6',
-        # buildbot depends on sqlalchemy internals, and these are the tested
-        # versions.
-        'sqlalchemy-migrate ==0.6.0, ==0.6.1, ==0.7.0, ==0.7.1, ==0.7.2',
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
-        setup_args['tests_require'] = None
-
 setup(**setup_args)
 
 # Local Variables:
