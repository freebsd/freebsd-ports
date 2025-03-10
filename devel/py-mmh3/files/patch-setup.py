--- setup.py.orig	2024-09-25 13:21:49 UTC
+++ setup.py
@@ -0,0 +1,10 @@
+from setuptools import Extension, setup
+
+mmh3module = Extension(
+    "mmh3", sources=["./src/mmh3/mmh3module.c", "./src/mmh3/murmurhash3.c"]
+)
+
+setup(
+    ext_modules=[mmh3module],
+    package_data={"mmh3": ["./src/mmh3/py.typed", "./src/mmh3/**.pyi"]},
+)
