--- setup.py.orig	2016-08-09 16:06:26 UTC
+++ setup.py
@@ -123,4 +123,5 @@ setup(
         'Programming Language :: Python :: 3.4',
         'Programming Language :: Python :: 3.5',
     ],
+    test_suite = 'nose.collector'
 )
