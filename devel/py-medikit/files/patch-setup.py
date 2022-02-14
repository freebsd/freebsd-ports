--- setup.py.orig	2020-11-25 07:42:37 UTC
+++ setup.py
@@ -56,11 +56,11 @@ setup(
     include_package_data=True,
     install_requires=[
         "git-semver ~= 0.3.2",
-        "jinja2 ~= 2.10",
+        "jinja2 >= 2.10",
         "mondrian ~= 0.8",
         "packaging ~= 20.0",
         "pip-tools ~= 4.5.0",
-        "semantic_version < 2.7",
+        "semantic_version ~= 2.8",
         "stevedore ~= 3.0",
         "whistle ~= 1.0",
         "yapf ~= 0.20",
