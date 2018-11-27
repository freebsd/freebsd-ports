--- setup.py.orig	2018-11-27 07:47:36 UTC
+++ setup.py
@@ -54,5 +54,5 @@ setup(name="datrie",
           ], include_dirs=[LIBDATRIE_DIR])
       ],
 
-      setup_requires=["pytest-runner"],
+      setup_requires=[],
       tests_require=["pytest", "hypothesis"])
