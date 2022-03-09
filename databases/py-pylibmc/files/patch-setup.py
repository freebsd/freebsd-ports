--- setup.py.orig	2019-08-15 11:49:27 UTC
+++ setup.py
@@ -125,4 +125,5 @@ setup(
         'Programming Language :: Python :: 3.6',
         'Programming Language :: Python :: 3.7',
     ],
+    test_suite = 'nose.collector'
 )
