--- setup.py.orig	2015-11-03 20:07:22 UTC
+++ setup.py
@@ -6,9 +6,9 @@ setup(
     version="1.3.0",
     packages=find_packages(exclude=["tests"]),
     scripts=['PyGitUp/gitup.py'],
-    install_requires=['GitPython==1.0.0', 'colorama==0.3.3',
-                      'termcolor==1.1.0', 'docopt==0.6.2',
-                      'six==1.9.0'],
+    install_requires=['GitPython>=1.0.0', 'colorama>=0.3.3',
+                      'termcolor>=1.1.0', 'docopt>=0.6.2',
+                      'six>=1.9.0'],
 
     # Tests
     test_suite="nose.collector",
