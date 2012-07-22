--- ./setup.py.orig	2012-07-14 18:23:43.000000000 +1000
+++ ./setup.py	2012-07-14 18:24:21.000000000 +1000
@@ -20,6 +20,7 @@
         'unittest2'
     ],
     test_suite='sanetime.test',
-    platforms=['any']
+    platforms=['any'],
+    zip_safe=False
 )
 
