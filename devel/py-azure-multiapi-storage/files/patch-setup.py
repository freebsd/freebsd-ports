# https://github.com/Azure/azure-multiapi-storage-python/pull/29/files

--- setup.py.orig	2020-07-08 12:22:39 UTC
+++ setup.py
@@ -18,6 +18,13 @@
 from setuptools import find_packages, setup
 import sys
 
+if sys.version_info[0] < 3:
+    packages = find_packages()
+else:
+    # ensure that the "azure" native namespace is coherent
+    from setuptools import find_namespace_packages
+    packages = find_namespace_packages(include=["azure.multiapi.*"])
+
 # azure v0.x is not compatible with this package
 # azure v0.x used to have a __version__ attribute (newer versions don't)
 try:
@@ -57,7 +64,7 @@ setup(
         'License :: OSI Approved :: Apache Software License',
     ],
     zip_safe=False,
-    packages=find_packages(exclude=["azure"]),
+    packages=packages,
     install_requires=[
         'azure-common',
         'cryptography',
