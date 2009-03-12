--- setup.py.orig	2009-02-23 22:14:56.000000000 +0800
+++ setup.py	2009-02-23 22:14:38.000000000 +0800
@@ -37,8 +37,8 @@
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
