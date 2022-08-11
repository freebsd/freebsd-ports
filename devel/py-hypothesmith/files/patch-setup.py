--- setup.py.orig	2021-11-27 08:58:08 UTC
+++ setup.py
@@ -32,7 +32,7 @@ setuptools.setup(
     license="MPL 2.0",
     description="Hypothesis strategies for generating Python programs, something like CSmith",
     zip_safe=False,
-    install_requires=["hypothesis>=5.41.0", "lark-parser>=0.7.2", "libcst>=0.3.8"],
+    install_requires=["hypothesis>=5.41.0", "lark>=0.7.2", "libcst>=0.3.8"],
     python_requires=">=3.6",
     classifiers=[
         "Development Status :: 4 - Beta",
