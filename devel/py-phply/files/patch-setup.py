--- setup.py.orig	2023-01-06 12:28:25 UTC
+++ setup.py
@@ -22,7 +22,7 @@ class GenerateParsetab(Command):
 
 setup(name="phply",
       version="1.2.6",
-      packages=find_packages(),
+      packages=find_packages(exclude=["tests"]),
       namespace_packages=['phply'],
       include_package_data=True,
       author='Ramen',
