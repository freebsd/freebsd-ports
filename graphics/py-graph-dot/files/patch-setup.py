
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -4,12 +4,7 @@
 import os
 
 
-try:
-    from setuptools import setup, find_packages
-except ImportError as ie:
-    import ez_setup
-    ez_setup.use_setuptools()
-    from setuptools import setup, find_packages
+from setuptools import setup, find_packages
 
 # Startup
 appname = "python-graph-dot"
@@ -20,7 +15,6 @@
         version = appversion,
         namespace_packages = ["pygraph"],
         packages = ["pygraph"] + [ os.path.join("pygraph", a) for a in find_packages("pygraph") ],
-        install_requires = [ 'python-graph-core==%s' % appversion, 'pydot' ],
         author = "Pedro Matiello",
         author_email = "pmatiello@gmail.com",
         description = "DOT support for python-graph",
