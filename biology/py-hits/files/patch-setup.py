-- Add setup.py to define extension modules.
-- This is needed because the current version of setuptools on FreeBSD does not
-- support defining ext-modules in pyproject.toml.

--- setup.py.orig	2026-05-29 15:20:01 UTC
+++ setup.py
@@ -0,0 +1,9 @@
+from setuptools import setup, Extension
+
+setup(
+    ext_modules=[
+        Extension("hits.adapters_cython", ["hits/adapters_cython.pyx"]),
+        Extension("hits.fastq_cython", ["hits/fastq_cython.pyx"]),
+        Extension("hits.sw_cython", ["hits/sw_cython.pyx"]),
+    ],
+)
