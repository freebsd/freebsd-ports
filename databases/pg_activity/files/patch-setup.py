--- ./setup.py.orig	2013-04-13 22:35:31.000000000 -0700
+++ ./setup.py	2013-04-13 22:37:21.000000000 -0700
@@ -17,7 +17,5 @@
         "psutil >= 0.4.1",
         "psycopg2 >= 2.2.1",
     ],
-    data_files = [
-        ('/usr/share/man/man1', ['docs/man/pg_activity.1'])
-    ],
+    zip_safe=False,
 )
