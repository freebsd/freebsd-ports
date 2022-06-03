--- setup.py.orig	2022-06-03 09:53:13 UTC
+++ setup.py
@@ -0,0 +1,9 @@
+#!/usr/bin/env python
+
+import setuptools
+
+if __name__ == "__main__":
+    setuptools.setup(
+        packages=['jsonschema'],
+        use_scm_version=True,
+    )
