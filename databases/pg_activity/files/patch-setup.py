--- ./setup.py.orig	2013-08-22 23:42:26.000000000 -0700
+++ ./setup.py	2013-08-22 23:42:36.000000000 -0700
@@ -27,4 +27,5 @@
         "psycopg2 >= 2.2.1",
     ],
     data_files = data_files,
+    zip_safe=False,
 )
