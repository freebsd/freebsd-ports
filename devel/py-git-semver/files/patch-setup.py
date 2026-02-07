--- setup.py.orig	2020-04-04 17:31:03 UTC
+++ setup.py
@@ -52,7 +52,7 @@ setup(
     classifiers=classifiers,
     packages=find_packages(exclude=['ez_setup', 'example', 'test']),
     include_package_data=True,
-    install_requires=['GitPython >= 3.1, < 3.2', 'semantic-version < 2.7'],
+    install_requires=['GitPython >= 3.1, < 3.2', 'semantic-version ~= 2.8'],
     extras_require={
         'dev': [
             'coverage ~= 4.5', 'isort', 'pytest ~= 4.6', 'pytest-cov ~= 2.7',
