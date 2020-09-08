--- setup.py.orig	2019-09-10 15:03:00 UTC
+++ setup.py
@@ -55,7 +55,7 @@ setup(
     include_package_data=True,
     install_requires=[
         'git-semver ~= 0.3.1', 'jinja2 ~= 2.10', 'mondrian ~= 0.8',
-        'packaging ~= 19.0', 'pip-tools ~= 4.0', 'semantic-version ~= 2.8',
+        'packaging >= 19.0', 'pip-tools ~= 4.0', 'semantic-version ~= 2.8',
         'stevedore ~= 1.28', 'whistle ~= 1.0', 'yapf ~= 0.20'
     ],
     extras_require={
