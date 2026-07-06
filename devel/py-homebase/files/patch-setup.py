-- Exclude test directory from package discovery to avoid installing it into site-packages.
--- setup.py.orig	2026-06-23 15:40:30 UTC
+++ setup.py
@@ -38,7 +38,7 @@ setup(
     author='D-Wave Systems Inc.',
     author_email='oshklarsky@dwavesys.com',
     long_description=readme(here),
-    packages=find_packages(),
+    packages=find_packages(exclude=["test", "test.*"]),
     install_requires=requirements(here),
     license='Apache 2.0',
     url='https://github.com/dwavesystems/homebase',
