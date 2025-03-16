--- setup.py.orig	2025-03-16 21:17:17 UTC
+++ setup.py
@@ -55,6 +55,6 @@ setup(
     extras_require={
         "test": tests_deps
     },
-    setup_requires=["pytest-runner"],
+    setup_requires=[],
     tests_require=tests_deps
 )
