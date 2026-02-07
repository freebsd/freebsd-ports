--- setup.py.orig	2022-08-06 21:23:04 UTC
+++ setup.py
@@ -123,4 +123,5 @@ setup(
         'Programming Language :: Python :: 3.10',
         'Programming Language :: Python :: 3 :: Only',
     ],
+    test_suite = 'nose.collector'
 )
