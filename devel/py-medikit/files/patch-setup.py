--- setup.py.orig	2020-04-04 17:34:58 UTC
+++ setup.py
@@ -54,8 +54,8 @@ setup(
     packages=find_packages(exclude=['ez_setup', 'example', 'test']),
     include_package_data=True,
     install_requires=[
-        'git-semver ~= 0.3.2', 'jinja2 ~= 2.10', 'mondrian ~= 0.8',
-        'packaging ~= 20.0', 'pip-tools ~= 4.5.0', 'semantic_version < 2.7',
+        'git-semver ~= 0.3.2', 'jinja2 >= 2.10', 'mondrian ~= 0.8',
+        'packaging >= 20.0', 'pip-tools ~= 4.5.0', 'semantic_version ~= 2.8',
         'stevedore ~= 1.28', 'whistle ~= 1.0', 'yapf ~= 0.20'
     ],
     extras_require={
