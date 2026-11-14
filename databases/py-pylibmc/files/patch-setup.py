--- setup.py.orig	2026-11-08 12:34:09 UTC
+++ setup.py
@@ -173,4 +173,5 @@ setup(
         'Programming Language :: Python :: Implementation :: CPython',
         'Programming Language :: Python :: Implementation :: PyPy',
     ],
+    test_suite = 'nose.collector'
 )
