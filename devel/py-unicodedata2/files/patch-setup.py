--- setup.py.orig	2026-09-19 18:48:52 UTC
+++ setup.py
@@ -0,0 +1,18 @@
+import sys
+from setuptools import setup, Extension
+
+module_sources = [
+    "./unicodedata2/unicodedata.c",
+    "./unicodedata2/unicodectype.c",
+]
+
+module1 = Extension(
+    "unicodedata2",
+    sources=module_sources,
+    include_dirs=["./unicodedata2/"],
+)
+
+setup(
+    name = "unicodedata2",
+    ext_modules = [module1],
+)
