--- setup.py.orig
+++ setup.py
@@ -4,11 +4,7 @@
 import os
 import logging
 
-try:
-    from setuptools import setup, find_packages
-except ImportError, ie:
-    import ez_setup
-    ez_setup.use_setuptools()
+from setuptools import setup, find_packages
 
 # Startup
 appname = "python-graph"
@@ -37,8 +33,8 @@
         name = appname,
         version = appversion,
         packages = ['graph', 'graph.algorithms', 'graph.algorithms.filters', 'graph.algorithms.heuristics', 'graph.classes'],
-        data_files = [(docsdir,docsfiles),
-                       (datadir,datafiles)],
+#        data_files = [(docsdir,docsfiles),
+#                       (datadir,datafiles)],
         author = "Pedro Matiello",
         author_email = "pmatiello@gmail.com",
         description = "A library for working with graphs in Python",
