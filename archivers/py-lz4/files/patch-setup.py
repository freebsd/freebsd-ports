--- setup.py.orig	2014-07-07 13:03:03 UTC
+++ setup.py
@@ -29,7 +29,7 @@ setup(
             "-DLZ4_VERSION=\"r119\"",
         ])
     ],
-    setup_requires=["nose>=1.0"],
+    tests_require=["nose>=1.0"],
     test_suite = "nose.collector",
     classifiers=[
         'Development Status :: 5 - Production/Stable',
