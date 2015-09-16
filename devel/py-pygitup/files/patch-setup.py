--- setup.py.orig	2015-07-01 09:15:37 UTC
+++ setup.py
@@ -6,8 +6,8 @@ setup(
     version="1.2.2",
     packages=find_packages(exclude=["tests"]),
     scripts=['PyGitUp/gitup.py'],
-    install_requires=['GitPython==0.3.2.1', 'colorama==0.3.2',
-                      'termcolor==1.1.0', 'docopt==0.6.1'],
+    install_requires=['GitPython>=0.3.2.1', 'colorama>=0.3.2',
+                      'termcolor>=1.1.0', 'docopt>=0.6.1'],
 
     # Tests
     test_suite="nose.collector",
