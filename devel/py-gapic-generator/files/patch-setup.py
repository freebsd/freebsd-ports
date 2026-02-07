--- setup.py.orig	2025-11-17 22:13:36 UTC
+++ setup.py
@@ -61,7 +61,7 @@ setuptools.setup(
     author="Google LLC",
     author_email="googleapis-packages@google.com",
     license="Apache 2.0",
-    packages=setuptools.find_namespace_packages(exclude=["docs", "tests"]),
+    packages=setuptools.find_namespace_packages(exclude=["docs", "tests", "tests.*"]),
     url=url,
     classifiers=[
         release_status,
