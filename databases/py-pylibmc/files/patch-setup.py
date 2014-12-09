--- setup.py.orig	2014-12-09 01:16:30 UTC
+++ setup.py
@@ -122,4 +122,5 @@ setup(
         'Programming Language :: Python :: 3.3',
         'Programming Language :: Python :: 3.4',
     ],
+    test_suite = 'nose.collector'
 )
