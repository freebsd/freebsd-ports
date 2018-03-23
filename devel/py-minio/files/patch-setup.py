--- setup.py.orig	2018-03-23 19:57:54 UTC
+++ setup.py
@@ -64,7 +64,7 @@ setup(
     packages=packages,
     install_requires=requires,
     tests_require=tests_requires,
-    setup_requires=['nose>=1.0'],
+    #setup_requires=['nose>=1.0'],
     license='Apache License 2.0',
     classifiers=[
         'Development Status :: 5 - Production/Stable',
