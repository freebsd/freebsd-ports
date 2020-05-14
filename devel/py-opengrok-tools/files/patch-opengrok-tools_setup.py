--- opengrok-tools/setup.py.orig	2020-03-26 19:43:15 UTC
+++ opengrok-tools/setup.py
@@ -32,7 +32,7 @@ setup(
     long_description=readme(),
     python_requires='>=3.4, <4',
     install_requires=[
-        'jsonschema==2.6.0',
+        'jsonschema>=2.6.0',
         'pyyaml',
         'requests>=2.20.0',
         'resource',
