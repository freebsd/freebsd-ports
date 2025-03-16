--- setup.py.orig	2025-03-16 21:08:30 UTC
+++ setup.py
@@ -60,5 +60,5 @@ setup(name="datrie",
           "include_dirs": [LIBDATRIE_DIR]})],
       ext_modules=ext_modules,
       python_requires=">=2.7, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*",
-      setup_requires=["pytest-runner", 'Cython>=0.28'],
+      setup_requires=['Cython>=0.28'],
       tests_require=["pytest", "hypothesis"])
