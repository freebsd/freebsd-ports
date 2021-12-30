--- setup.py.orig	2021-09-05 21:12:23 UTC
+++ setup.py
@@ -47,7 +47,7 @@ setup(
     author_email="tom@tomchristie.com",
     packages=get_packages("databases"),
     package_data={"databases": ["py.typed"]},
-    data_files=[("", ["LICENSE.md"])],
+    # data_files=[("", ["LICENSE.md"])],
     install_requires=['sqlalchemy>=1.4,<1.5', 'aiocontextvars;python_version<"3.7"'],
     extras_require={
         "postgresql": ["asyncpg"],
