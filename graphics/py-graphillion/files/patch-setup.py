--- ./setup.py.orig	2013-06-21 19:44:04.348822813 +1000
+++ ./setup.py	2013-06-21 19:44:14.872371187 +1000
@@ -51,4 +51,5 @@
                   ),
         ],
       test_suite='graphillion.test',
+      zip_safe=False,
       )
