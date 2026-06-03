--- setup.py.orig	2025-08-09 03:16:34 UTC
+++ setup.py
@@ -1,4 +1,14 @@
-
 from setuptools import setup
 
-setup(package_data={'flask_cors-stubs': ['__init__.pyi', 'core.pyi', 'decorator.pyi', 'extension.pyi', 'version.pyi', 'METADATA.toml', 'py.typed']})
+setup(
+    name='types-Flask-Cors',
+    version='6.0.0.20250809',
+    description='Typing stubs for Flask-Cors',
+    license='Apache-2.0',
+    packages=['flask_cors-stubs'],
+    package_data={'flask_cors-stubs': ['__init__.pyi', 'core.pyi', 'decorator.pyi', 'extension.pyi', 'version.pyi', 'METADATA.toml', 'py.typed']},
+    install_requires=['Flask>=2.0.0'],
+    python_requires='>=3.9',
+    zip_safe=False,
+    include_package_data=True
+)
