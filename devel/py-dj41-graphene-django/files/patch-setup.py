--- setup.py.orig	2020-12-31 06:55:53 UTC
+++ setup.py
@@ -68,7 +68,6 @@ setup(
         "promise>=2.1",
         "text-unidecode",
     ],
-    setup_requires=["pytest-runner"],
     tests_require=tests_require,
     rest_framework_require=rest_framework_require,
     extras_require={
