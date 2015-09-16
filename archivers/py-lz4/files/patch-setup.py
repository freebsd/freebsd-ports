--- setup.py.orig	2014-07-07 13:03:03 UTC
+++ setup.py
@@ -4,10 +4,11 @@
 from setuptools import setup, find_packages, Extension
 
 VERSION = (0, 7, 0)
+VERSION_STR = ".".join([str(x) for x in VERSION])
 
 setup(
     name='lz4',
-    version=".".join([str(x) for x in VERSION]),
+    version=VERSION_STR,
     description="LZ4 Bindings for Python",
     long_description=open('README.rst', 'r').read(),
     author='Steeve Morin',
@@ -26,10 +27,11 @@ setup(
             "-Wall",
             "-W",
             "-Wundef",
+            "-DVERSION=\"%s\"" % VERSION_STR,
             "-DLZ4_VERSION=\"r119\"",
         ])
     ],
-    setup_requires=["nose>=1.0"],
+    tests_require=["nose>=1.0"],
     test_suite = "nose.collector",
     classifiers=[
         'Development Status :: 5 - Production/Stable',
