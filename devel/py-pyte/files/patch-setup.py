--- setup.py.orig	2022-04-10 17:54:50 UTC
+++ setup.py
@@ -35,7 +35,6 @@ setup(name="pyte",
       version="0.8.1",
       packages=["pyte"],
       install_requires=["wcwidth"],
-      setup_requires=["pytest-runner"],
       tests_require=["pytest"],
       platforms=["any"],
 
