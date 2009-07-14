--- setup.py.orig
+++ setup.py
@@ -4,12 +4,7 @@
 import os
 import logging
 
-try:
-    from setuptools import setup, find_packages
-except ImportError, ie:
-    import ez_setup
-    ez_setup.use_setuptools()
-    from setuptools import setup, find_packages
+from setuptools import setup, find_packages
 
 # Startup
 appname = "python-graph"
@@ -40,9 +35,6 @@
         name = appname,
         version = appversion,
         packages = ['pygraph', 'pygraph.algorithms', 'pygraph.algorithms.filters', 'pygraph.algorithms.heuristics', 'pygraph.classes', 'pygraph.readwrite'],
-        data_files = [(docsdir,docsfiles),
-                       (datadir,datafiles)],
-        install_requires = ['pydot'],
         author = "Pedro Matiello",
         author_email = "pmatiello@gmail.com",
         description = "A library for working with graphs in Python",
