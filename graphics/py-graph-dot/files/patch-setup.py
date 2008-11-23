--- setup.py.orig	2008-10-28 21:22:57.000000000 +0800
+++ setup.py	2008-10-28 21:23:17.000000000 +0800
@@ -18,9 +18,9 @@
         name = appname,
         version = appversion,
         packages = ['graph'],
-        data_files = [(docfolder, ['README','Changelog','COPYING']),
-                                (docfolder + docs, docfiles),
-                                ],
+#        data_files = [(docfolder, ['README','Changelog','COPYING']),
+#                                (docfolder + docs, docfiles),
+#                                ],
 
         # metadata
         author = "Pedro Matiello",
