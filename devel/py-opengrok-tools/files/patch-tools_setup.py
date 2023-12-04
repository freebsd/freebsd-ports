--- tools/setup.py.orig	2021-02-17 15:55:36 UTC
+++ tools/setup.py
@@ -31,7 +31,7 @@ setup(
     long_description=readme(),
     python_requires='>=3.4, <4',
     install_requires=[
-        'jsonschema==2.6.0',
+        'jsonschema>=2.6.0',
         'pyyaml',
         'requests>=2.20.0',
         'resource',
