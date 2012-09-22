--- ./setup.py.orig	2012-01-26 06:31:16.000000000 +1100
+++ ./setup.py	2012-09-15 01:20:41.000000000 +1000
@@ -83,6 +83,8 @@
           'Programming Language :: Python :: 2.6',
           'Programming Language :: Python :: 2.7',
           ],
+    test_suite='test',
+    zip_safe=False,
     )
 
 if os.name == 'posix':
