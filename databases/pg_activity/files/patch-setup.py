--- setup.py.orig	2016-10-04 13:50:12 UTC
+++ setup.py
@@ -26,4 +26,5 @@ setup(
         "psycopg2 >= 2.2.1",
     ],
     data_files = data_files,
+    zip_safe=False,
 )
