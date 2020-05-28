Allow to use hypothesis 4.x, which works just fine.

Remove this patch when py-hypothesis is updated to >=5.10.4
--- setup.py.orig	2020-05-17 15:41:01 UTC
+++ setup.py
@@ -32,7 +32,7 @@ setuptools.setup(
     license="MPL 2.0",
     description="Hypothesis strategies for generating Python programs, something like CSmith",
     zip_safe=False,
-    install_requires=["hypothesis>=5.10.4", "lark-parser>=0.7.2", "libcst>=0.3.4"],
+    install_requires=["hypothesis>=4.57.1", "lark-parser>=0.7.2", "libcst>=0.3.4"],
     python_requires=">=3.6",
     classifiers=[
         "Development Status :: 2 - Pre-Alpha",
